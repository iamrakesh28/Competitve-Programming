#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getNumberOfIntegers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING L
 *  2. STRING R
 *  3. INTEGER K
 */
const int prime = 1e9 + 7;
long long dp[105][105][2];

long long find(string S, int K) {
    int n = S.length();
    for (int i = n; i >= 0; i--)
        for (int m = 0; m < 2; ++m)
            for (int j = 0; j <= K; ++j) {
                if (i == n) {
                    if (j)
                        dp[i][j][m] = 0;
                    else    
                        dp[i][j][m] = 1;
                    continue;
                }
                if (j == 0) {
                    dp[i][j][m] = 1;
                    continue;
                }
                int v = S[i] - '0';
                if (m == 0)
                    v = 9;
                dp[i][j][m] = 0;
                for (int r = 0; r <= v; ++r) {
                    if (m) {
                        if (r) {
                            if (r == v)
                                dp[i][j][m] = (dp[i][j][m] + dp[i + 1][j - 1][m]) % prime;
                            else
                                dp[i][j][m] = (dp[i][j][m] + dp[i + 1][j - 1][0]) % prime;
                        }
                        else {
                            if (r == v)
                                dp[i][j][m] = (dp[i][j][m] + dp[i + 1][j][m]) % prime;
                            else
                                dp[i][j][m] = (dp[i][j][m] + dp[i + 1][j][0]) % prime;
                        }
                    }
                    else {
                        if (r)
                            dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j - 1][0]) % prime;
                        else
                            dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % prime;
                    }
                } 
            }
    return dp[0][K][1];
}
long long getNumberOfIntegers(string L, string R, int K) {
    long long ans = find(R, K);
    ans = ans - find(L, K);
    //cout<<ans<<endl;
    ans = (ans + prime) % prime;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string L;
    getline(cin, L);

    string R;
    getline(cin, R);

    string K_temp;
    getline(cin, K_temp);

    int K = stoi(ltrim(rtrim(K_temp)));

    long long ans = getNumberOfIntegers(L, R, K);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


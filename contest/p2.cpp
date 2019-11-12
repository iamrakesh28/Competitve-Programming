#include <iostream>
#include <cstring>

using namespace std;

const int prime = 1e9 + 7;
char S[505];
int n;
long long dp[505][505];

long long solve(int i, int j) {
    if (i == n) {
		//cout<<j<<endl;
        return 1;
	}
    if (dp[i][j] == -1) {
        int found = 1, inc = 0;
        dp[i][j] = 0;
        for (int k = i, cnt = 0; k < n; ++k, cnt++) {
			//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<" "<<inc<<endl;
			if (inc) {
				dp[i][j] = (dp[i][j] + solve(k + 1, i)) % prime;
				continue;
			}
            if (j + cnt < i) {
				if (S[j + cnt] == S[k])
                	dp[i][j] = (dp[i][j] + solve(k + 1, i)) % prime;
				else if (S[j + cnt] < S[k]) {
					dp[i][j] = (dp[i][j] + solve(k + 1, i)) % prime;
					inc = 1;
				}
				else
					found = 0;
            }
            if (j + cnt >= i)
                dp[i][j] = (dp[i][j] + solve(k + 1, i)) % prime;
            if (found == 0)
               break;
        }
    }
    return dp[i][j];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%s", S);
    n = strlen(S);
    memset(dp, -1, sizeof dp);
    long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + solve(i + 1, 0)) % prime; 
    printf("%lld\n", ans);
    return 0;
}



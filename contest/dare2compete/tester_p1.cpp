#include<iostream>

using namespace std;

const int N = 1000;
const long long INF = static_cast<long long>(1e15);

int n;
char s[N], t[N];    // s: source, t: target
long long f[N], b[N], dp[N + 1][N];
// dp[i][j] = min cost to build s[j..i-j+1]

void readInput() {
    
    scanf("%d", &n);            // Input length n
    
    for(int i = 0;i < n;i++)    // Input string using which to build: source string
        scanf(" %c", &s[i]);

    for(int i = 0;i < n;i++)    // Input string to build: target string
        scanf(" %c", &t[i]);

    for(int i = 0;i < n;i++)    // Input Forward Insertion Costs
        scanf(" %lld", &f[i]);

    for(int i = 0;i < n;i++)    // Input Backward Insertion Costs
        scanf(" %lld", &b[i]);
}

void computeDP() {

    for(int j = 0;j < n;j++)
        dp[1][j] = (s[0] == t[j] ? min(f[0], b[0]) : INF);

    for(int i = 2;i <= n;i++) {
        for(int j = 0;j < n;j++) {

            dp[i][j] = INF;

            if(j + i > n)
                continue;

            if(s[i - 1] == t[j])
                dp[i][j] = min(dp[i][j], (dp[i - 1][j + 1] == INF ? INF : f[i - 1] + dp[i - 1][j + 1]));

            if(s[i - 1] == t[j + i - 1])
                dp[i][j] = min(dp[i][j], (dp[i - 1][j] == INF ? INF : b[i - 1] + dp[i - 1][j]));
        }
    }
}

int main() {

    int tc;
    scanf("%d", &tc);

    while(tc --) {
        readInput();
        computeDP();
        if(dp[n][0] == INF)
            printf("cannot be formed\n");
        else
            printf("%lld\n", dp[n][0]); // Print Ans
    }

    return 0;
}
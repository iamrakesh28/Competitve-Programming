#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; i++)
#define rep3(i, b, n) for (int i = b; i < n; i++)
#define coord pair<double,double>
#define line pair<coord,coord>

using namespace std;

int NCPC[301][301];
int BCEW[301][301];
int m[31];
int T1, T2, n;

int dp[31][301][301];
int path[31][301][301];

int find_plan(int site, int t1,int t2) {
    if (dp[site][t1][t2] != -1)
        return dp[site][t1][t2];
    else if(t1 == T1 && t2 == T2 )
        return 0;
    else if (t1 > T1 || t2 > T2)
        return 2e8;

    dp[site][t1][t2] = 2e8;
    int i,j;
    for (i=0,j=m[site]; i <= m[site]; i++,j--) {
        int site_cost = NCPC[site][i] + BCEW[site][j];
        int tmp = find_plan(site+1, t1+i, t2+j) + site_cost;
        if(dp[site][t1][t2] > tmp){
            path[site][t1][t2] = i;
            dp[site][t1][t2] = tmp;
        }
    }
    return dp[site][t1][t2];
}

int main() {
    while(cin >> T1 >> T2 && T1 + T2) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        rep(i, n) {
            cin >> m[i];
            rep(j,m[i]) cin >> NCPC[i][j+1];
            rep(j,m[i]) cin >> BCEW[i][j+1];
        }
        cout << find_plan(0,0,0) << endl;
        int t1=0, t2=0, i=0;
        while (t1 != T1 || t2 != T2) {
            cout << (i ? " " : "") << path[i][t1][t2];
            int tmp = t1;
            t1 = t1 + path[i][t1][t2];
            t2 = t2 + m[i] - path[i][tmp][t2];
            i++;
        }
        cout << endl << endl;
    }
}

#include <iostream>

using namespace std;

const int N = 5e3 + 5;
const long long inf = 1e15;

long long dp[N][N];
pair <int, int> voter[N];
int cnt[N];

int main () {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
	  cnt[i] = 0;
	for (int i = 0; i < n; ++i) {
	    scanf("%d%d", &voter[i].first, &voter[i].second);
	    cnt[voter[i].first]++;
	}

	for (int i = 0; i < n; ++i)
	  cnt[i + 1] += cnt[i];
	for (int i = 0; i <= n; ++i) {
	  int num = cnt[i];
	  while (num != cnt[num])
	    num = cnt[num];
	  cnt[i] = num;
	  //cout<<cnt[i]<<" "<<i<<endl;
	}
	for (int i = 0; i <= n; ++i) {
	  for (int j = 0; j <= n; ++j) {
	    if (i == 0) {
	      if (j == 0)
		dp[i][j] = 0;
	      else
		dp[i][j] = inf;
	      continue;
	    }
	    if (j == 0)
	      dp[i][j] = dp[i - 1][j];
	    else {
	      dp[i][j] = dp[i - 1][j];
	      if (n - j < voter[i - 1].first) {
		int teams = cnt[n - j + 1];
		if (teams < voter[i - 1].first)
		  teams++;
		if (teams < cnt[teams])
		  teams = cnt[teams];
		//if (q == 0) {
		//cout<<teams<<" "<<i<<" "<<j<<endl;
		//}
		dp[i][j] = min(dp[i][j], dp[i - 1][n - teams] + voter[i - 1].second);
	      }
	      //cout<<i<<" "<<j<<" "<<teams<<" "<<dp[i][j]<<endl;
	    }
	  }
	}
	printf("%lld\n", dp[n][n - cnt[0]]);
    }
}

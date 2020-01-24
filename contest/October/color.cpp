#include <iostream>
#include <list>

using namespace std;

const int N = 1e5;
const long long inf = 1e16;
long long c1[N], c2[N], c3[N], dp[N][6];
list <int> adj[N];
int deg[N], an[N];
int col[N];

void dfs(int u, int p) {

	dp[u][0] = c1[u];
	dp[u][1] = c1[u];
	dp[u][2] = c2[u];
	dp[u][3] = c2[u];
	dp[u][4] = c3[u];
	dp[u][5] = c3[u];

	long long val = inf;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u);
			// c1
			dp[u][0] = dp[v][2] + c1[u];
			dp[u][1] = dp[v][5] + c1[u];

			// c2
			dp[u][2] = dp[v][4] + c2[u];
			dp[u][3] = dp[v][1] + c2[u];

			// c3
			dp[u][4] = dp[v][0] + c3[u];
			dp[u][5] = dp[v][3] + c3[u];

			for (int i = 0; i < 6; ++i)
				if (val > dp[u][i]) {
					val = dp[u][i];
					col[u] = i;
				}
		}
	}
}

void dfs2(int u, int p, int c) {

	if (c <= 1)
		an[u] = 0;
	else if (c <= 3)
		an[u] = 1;
	else
		an[u] = 2;
	int d;
	//cout<<c + 1<<" "<<u+1<<endl;
	for (int v : adj[u])
		if (v != p) {
			switch (c) {
				case 0 : d = 2; break;
				case 1 : d = 5; break;
				case 2 : d = 4; break;
				case 3 : d = 1; break;
				case 4 : d = 0; break;
				default : d = 3;
			}
			dfs2(v, u, d);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, one;
	bool poss = true;
	cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>c1[i];
	for (int i = 0; i < n; ++i)
		cin>>c2[i];
	for (int i = 0; i < n; ++i)
		cin>>c3[i];
	int u, v;
	for (int i = 0; i < n - 1; ++i) {
		cin>>u>>v;
		u--, v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
		deg[u]++;
		deg[v]++;
		if (deg[u] > 2 || deg[v] > 2)
			poss = false;
	}
	if (poss == false) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; ++i)
		if (deg[i] == 1) {
			one = i;
			break;
		}
	dfs(one, one);
	long long ans = inf;
	dfs2(one, one, col[one]);
	for (int i = 0; i < 6; ++i)
		ans = min(ans, dp[one][i]);
	cout<<ans<<endl;
	for (int i = 0; i < n; ++i)
		cout<<(an[i] + 1)<<" ";
	cout<<endl;
	return 0;
}

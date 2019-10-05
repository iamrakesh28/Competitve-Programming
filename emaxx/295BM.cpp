#include <bits/stdc++.h>

using namespace std;

long long adj[500][500], xi[500], ans[500];

void solve(int k)
{
	for (int i = 0; i <= k; ++i) {
		if (i == k) {
			for (int r = 0; r <= k; ++r)
				for (int c = 0; c <= k; ++c)
					adj[xi[r] - 1][xi[c] - 1] = min(adj[xi[r] - 1][xi[c] - 1], adj[xi[r] - 1][xi[i] - 1] + adj[xi[i] - 1][xi[c] - 1]);
		}
		else {
			for (int r = 0; r < k; ++r)
				adj[xi[r] - 1][xi[k] - 1] = min(adj[xi[r] - 1][xi[k] - 1], adj[xi[r] - 1][xi[i] - 1] + adj[xi[i] - 1][xi[k] - 1]);
			for (int r = 0; r <= k; ++r)
				adj[xi[k] - 1][xi[r] - 1] = min(adj[xi[k] - 1][xi[r] - 1], adj[xi[k] - 1][xi[i] - 1] + adj[xi[i] - 1][xi[r] - 1]);
		}
	}
}

long long calc(int i)
{
	long long ans = 0;
	for (int r = 0; r <= i; ++r) 
		for (int c = 0; c <= i; ++c)
			ans += adj[xi[r] - 1][xi[c] - 1];
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin>>adj[i][j];
	for (int i = 0; i < n; ++i)
		cin>>xi[i];
	reverse(xi, xi + n);
	for (int i = 0; i < n; i++) {
		solve(i);
		ans[i] = calc(i);
	}
	reverse(ans, ans + n);
	for (int i = 0; i < n; ++i)
		cout<<ans[i]<<" ";
	printf("\n");
	return 0;
}

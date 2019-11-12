#include <bits/stdc++.h>

using namespace std;

vector <int> tin, tout, parent;
int cnt;

void dfs(int u, int p) {

	parent[u] = p;
	cnt++;
	//cout<<u<<" "<<p<<endl;
	while (cnt != tout[u])
		dfs(tin[cnt], u);
}
int main() {

	int n;
	scanf("%d", &n);
	tin.resize(2 * n);
	tout.resize(2 * n);
	parent.resize(n);
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		tin[t] = i;
	}
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		tout[i] = t;
	}
	dfs(tin[0], -1);
	for (int i = 0; i < n; ++i)
		printf("%d ", parent[i] + 1);
	printf("\n");
	return 0;
}

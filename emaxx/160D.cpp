#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e5;
struct Edge {
	int u, v, w;
} edge[maxm];

pair <int, int> edgE[maxm];
int par[maxm], size[maxm], val[maxm], low[maxm], num[maxm], t = 0;
list <pair<int, int>> adj[maxm];
bool visit[maxm];

int find(int u) 
{
	if (u == par[u])
		return u;
	return find(par[u]);
}

void join(int u, int v) {

	if (u == v)
		return;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
	}
	else {
		size[v] += size[u];
		par[u] = v;
	}
}
void solve(int start, int i) {
	int u, v, ind;
	for (int j = start; j < i; ++j) {
		ind = edgE[j].second;
		int x = edge[ind].u, y = edge[ind].v;
		u = find(x), v = find(y);
		if (u == v) {
			val[ind] = 2;
			continue;
		}
		adj[x].push_back(make_pair(ind, y));
		adj[y].push_back(make_pair(ind, x)); 
	}
	for (int j = start; j < i; ++j) {
		ind = edgE[j].second;
		u = find(edge[ind].u), v = find(edge[ind].v);
		join(u, v);
	}
}

void dfs(int u, int p) {

	visit[u] = true;
	low[u] = num[u] = t++;
	for (auto it : adj[u]) {
		
		if (visit[it.second] == false) {
			dfs(it.second, u);
			if (low[it.second] > num[u])
				val[it.first] = 0;
			low[u] = min(low[u], low[it.second]);
		}
		else if (it.second != p)
			low[u] = min(low[u], num[it.second]);
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edge[i] = {a - 1, b - 1, w};
		edgE[i] = {w, i};
		val[i] = 1;
	}
	sort(edgE, edgE + m);
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		size[i] = 1;
		visit[i] = false;
	}
	int start = 0;
	for (int i = 1; i < m; ++i) {
		if (edgE[i - 1].first == edgE[i].first)
			continue;
		else {
			solve(start, i);
			start = i;
		}
	}
	solve(start, m);
	for (int i = 0; i < m; ++i)
		cout<<val[i]<<endl;
	dfs(0,0);
	for (int i = 0; i < m; ++i) {
		switch(val[i]) {
			case 0 : printf("any\n"); break;
			case 1 : printf("at least one\n"); break;
			case 2 : printf("none\n");
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int par[10000], size[10000], cnt, ai;
bool airport[10000];
pair <int, pair <int, int>> edge[200000];

int find(int u) {
	
	if (u == par[u]) 
		return u;
	return find(par[u]);
}

bool compare(pair <int, pair<int, int>> &a, pair <int, pair<int, int>> &b) {
	
	if (a.first != b.first)
		return a.first < b.first;
	if (a.second.first == a.second.second && b.second.first == b.second.second)
		return a.second.first < b.second.first;
	if (a.second.first == a.second.second)
		return true;
	return false;
}
int join(int u, int v, int c, int a) {
	
	if (u == v) {
		u = find(u);
		//cout<<u<<endl;
		if (airport[u])
			return 0;
		airport[u] = true;
		cnt++;
		return a;
	}
	u = find(u);
	v = find(v);
	if (u == v)
		return 0;
	if (airport[u] && airport[v])
		return 0;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
		if (airport[u] || airport[v])
			airport[u] = true;
		return c;
	}
	else {
		size[v] += size[u];
		par[u] = v;
		if (airport[u] || airport[v])
			airport[v] = true;
		return c;
	}
}
int main() {

	int t, i = 0;
	scanf("%d", &t);
	while (t--) {
		int n, m, d = 0;
		cnt = 0;
		scanf("%d%d%d", &n, &m, &ai);
		//cout<<n<<" "<<m<<" "<<ai<<endl;
		for (int i = 0; i < m; ++i) {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			if (x == y) {
				d--;
				continue;
			}
			edge[i + d].first = c;
			edge[i + d].second.first = x - 1;
			edge[i + d].second.second = y - 1;
		}
		m += d;
		for (int i = 0; i < n; ++i) {
			edge[i + m].first = ai;
			edge[i + m].second.first = i;
			edge[i + m].second.second = i;
		}
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			size[i] = 1;
			airport[i] = false;
		}
		sort(edge, edge + m + n, compare);
		//cout<<m + n<<endl;
		int ans = 0;
		for (int i = 0; i < m + n; ++i) {
			int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
			//cout<<u<<" "<<v<<" "<<c<<endl;
			ans += join(u, v, c, ai);
		}
		printf("Case #%d: %d %d\n", i + 1, ans, cnt);
		i++;
	}
	return 0;
}

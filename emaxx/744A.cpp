#include <bits/stdc++.h>

using namespace std;

int size[1000], par[1000], edge[1000], arr[1000];
bool cmp[1000];

int find(int u) {
	if (u == par[u])
		return u;
	return find(par[u]);
}

void join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		edge[u]++;
		return;
	}
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
		edge[u]++;
	}
	else {
		size[v] += size[u];
		par[u] = v;
		edge[v]++;
	}
}
int main() {

	int n, m, k, ans = 0, maxm;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		size[i] = 1;
		edge[i] = 0;
		cmp[i] = false;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", arr + i);
		arr[i]--;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		join(u - 1, v - 1);
	}
	maxm = find(arr[0]);
	for (int i = 0; i < k; ++i) {
		int a = find(arr[i]);
		if (size[maxm] < size[a])
			maxm = a;
		ans = ans + (size[a]) * (size[a] - 1) / 2 - edge[a];
		edge[a] = (size[a]) * (size[a] - 1) / 2;
		//cout<<ans<<" "<<arr[i]+1<<endl;
		cmp[a] = true;
	}
	int cnt = 0, d = 0;
	for (int i = 0; i < n; ++i) {
		int a = find(i);
		if (cmp[a] == true)
			continue;
		cnt += size[a];
		d += edge[a];
		cmp[a] = true;
	}
	//cout<<ans<<endl;
	int a = cnt + size[maxm];
	ans = ans + a * (a - 1) / 2 - d - edge[maxm];
	printf("%d\n", ans);
	
}

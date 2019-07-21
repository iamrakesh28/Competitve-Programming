#include <bits/stdc++.h>

using namespace std;

int par[100000], size[100000];
bool cmp[100000];

int find(int u) {
	if (u == par[u])
		return u;
	return find(par[u]);
}

void join(int u, int v) {

	u = find(u), v = find(v);
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

long long exp(long long a, int x, long long prime) {

	long long r = 1;
	while (x > 0) {
		if (x & 1)
			r = (r * a) % prime;
		a = (a * a) % prime;
		x >>= 1;
	}
	return r;
}
int main() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		size[i] = 1;
		cmp[i] = false;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		join(a - 1, b - 1);
	}
	for (int i = 0; i < n; ++i)
		cmp[find(i)] = true;
	int cnt = 0;
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		if (cmp[i] == true) {
			cnt++;
			//cout<<i<<" "<<u<<endl;
			ans = (ans * size[i]) % k;
		}
	}
	ans = (ans * exp(cnt, cnt - 2, k)) % k;
	cout<<ans<<endl;
	return 0;
}

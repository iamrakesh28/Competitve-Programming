#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int par[N], size[N];

int find(int u) {
	if (u == par[u])
		return u;
	par[u] = find(par[u]);
	return par[u];
}

void join(int x, int y) {

	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (size[x] > size[y]) {
		size[x] += size[y];
		par[y] = x;
	}
	else {
		size[y] += size[x];
		par[x] = y;
	}
}

int main() {

	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		size[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		join(u, v);
	}
	//cout<<size[find(3)]<<endl;
	for (int i = 0; i < n;) {
		if (size[find(i)] > 1) {
			int j;
			//cout<<size[find(i)]<<endl;
			for (j = i + 1; j < i + size[find(i)]; ++j) {
				int x = find(i);
				int y = find(j);
				//cout<<size[x]<<" "<<size[y]<<" "<<y+1<<" "<<j+1<<endl;
				if (x == y)
					continue;
				join(x, y);
				//cout<<size[find(x)]<<"-"<<size[find(y)]<<endl;
				//cout<<x+1<<" "<<y+1<<" "<<i+1<<" "<<j<<" "<<size[x]<<endl;
				ans++;
			}
			i = j;
		}
		else
			i++;
	}
	printf("%d\n", ans);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long adj[250][250], **r, **a, **temp;
vector <long long **> point;
const long long inf = 1e15;

void mult(int n, long long **A, long long **B) {
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp[i][j] = inf;
			for (int k = 0; k < n; ++k)
				temp[i][j] = min(temp[i][j], A[i][k] + B[k][j]);
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			A[i][j] = temp[i][j];
}

long long power(int k, int n) {

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			r[i][j] = adj[i][j];
	int num = 0;
	while (k) {
		if (k & 1)
			mult(n, r, point[num]);
		num++;
		k = k >> 1;
	}
	long long w = inf;
	for (int i = 0; i < n; ++i)
		w = min(w, r[i][i]);
	return w;
}

int main() {
	
	int n, m;
	scanf("%d%d", &n, &m);
	temp = new long long *[n];
	r = new long long *[n];
	a = new long long *[n];
	for (int i = 0; i < n; ++i) {
		temp[i] = new long long [n];
		r[i] = new long long [n];
		a[i] = new long long [n];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i == j)
				adj[i][j] = 0, a[i][j] = 0;
			else
				adj[i][j] = inf, a[i][j] = inf;

	for (int i = 0; i < m; ++i) {
		int u, v, t, h;
		scanf("%d%d%d%d", &u, &v, &t, &h);
		u--, v--;
		adj[u][v] = min(adj[u][v], (long long) (t - h));
		a[u][v] = adj[u][v];
	}
	int beg = 1, end = n, mid, ans = 1, t = ceil(log2(n)) + 1;
	point.push_back(a);
	for (int q = 0; q <= t; ++q) {
		long long **c = new long long *[n];
		for (int i = 0; i < n; ++i) {
			c[i] = new long long [n];
			for (int j = 0; j < n; ++j)
				c[i][j] = point[q][i][j];
		}
		mult(n, c, c);
		point.push_back(c);
	}
	long long weight;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		long long w = power(mid - 1, n);
		if (w < 0) {
			ans = mid;
			weight = w;
			end = mid - 1;
		}
		else
			beg = mid + 1;
	}
	printf("%d %lld\n", ans, -weight);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const  double eps = 1e-18;
int cell(int i, int j, int m) {
	return i * m + j;
}

int deg[25], adj[25][25], dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m) {
	if (i >= 0 && j >= 0 && i < n && j < m)
		return true;
	return false;
}

void deter(int n) {

	vector < vector <  double>> a (n, vector <  double> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = ( double)adj[i][j];
	for (int i = 0; i < n; ++i)
		a[i][i] = ( double)deg[i] - a[i][i];
	 double det = 1;
	for (int i = 0; i < n; ++i) {
		int k = i;
		for (int j = i + 1; j < n; ++j)
			if (abs(a[j][i]) > abs(a[k][i]))
				k = j;
		// det = 0; skipped
		if (abs(a[k][i]) < eps) {
			det = 0;
			break;
		}
		//for (int j = i; j < n; ++j)
			//swap(a[k][j], a[i][j]);
		swap(a[i], a[k]);
		if (i != k)
			det = -det;
		det *= a[i][i];
		for (int j = i + 1; j < n; ++j)
			a[i][j] /= a[i][i];
		for (int j = 0; j < n; ++j)
			if (j != i && abs(a[j][i]) > eps)
				for (int k = i + 1; k < n; ++k)
					a[j][k] -= a[i][k] * a[j][i];
	}
	//ans = det;
	cout<<det<<endl;
	/*  double diff = det - (  double)ans;
	if (diff >= 0.5)
		ans++;*/
	//cout<<det<<endl;
	//printf("%0.0Lf\n", det);
	return ;
}
int main() {
	
	int w, h, k;
	scanf("%d%d%d", &h, &w, &k);
	for (int i = 0; i < h * w; ++i)
		deg[i] = 0;
	for (int i = 0; i < h * w; ++i)
		for (int j = 0; j < h * w; ++j)
			adj[i][j] = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int u = cell(i, j, w), v;
			for (int d = 0; d < 4; ++d) {
				int r = dy[d] + i, c = dx[d] + j;
				if (valid(r, c, h, w)) {
					v = cell(r, c, w);
					adj[u][v]++;
					deg[u]++;
				}
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		r1 = cell(r1, c1, w);
		r2 = cell(r2, c2, w);
		adj[r2][r1] = adj[r1][r2] = 0;
		deg[r1]--, deg[r2]--;
	}
	/*for (int i = 0; i < h * w; ++i) {
		for (int j = 0; j < h * w; ++j)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	} */
	deter(h * w - 1);
	return 0;
}

#include <iostream>

using namespace std;

#define N 1000

int mat[N][N], r1[N][N], r2[N][N], c1[N][N], c2[N][N];
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", mat[i] + j);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		r1[i][0] = mat[i][0];
		for (int j = 1; j < m; ++j) {
			r1[i][j] = min(r1[i][j - 1] + mat[i][j], mat[i][j]);
			//cout<<r1[i][j]<<" ";
		}
		//cout<<endl;
	}
	for (int i = 0; i < n; ++i) {
		r2[i][m - 1] = mat[i][m - 1];
		for (int j = m - 2; j >= 0; --j) {
			r2[i][j] = min(r2[i][j + 1] + mat[i][j], mat[i][j]);
			//cout<<r2[i][j]<<" ";
		}
		//cout<<endl;
	}
	for (int j = 0; j < m; ++j) {
			c1[0][j] = mat[0][j];
			//cout<<r2[i][j]<<" ";
		}
	for (int j = 0; j < m; ++j) {
			c1[n - 1][j] = mat[n - 1][j];
			//cout<<r2[i][j]<<" ";
		}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			c1[i][j] = min(c1[i - 1][j] + mat[i][j], mat[i][j]);
			//cout<<r2[i][j]<<" ";
		}
		//cout<<endl;
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			c2[i][j] = min(c2[i + 1][j] + mat[i][j], mat[i][j]);
			//cout<<c2[i][j]<<" ";
		}
		//cout<<endl;
	}
	long long temp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			temp = r1[i][j] + r2[i][j] + c1[i][j] + c2[i][j] - 3 * mat[i][j];
			ans = min(ans, temp);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

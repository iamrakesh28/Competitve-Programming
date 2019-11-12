#include <bits/stdc++.h>

#define N 300
const int inf = 1e9;
using namespace std;

int Max[N][N][N], Min[N][N][N], mat[N][N];
bool temp[N];

void calc(int r, int c) {

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int d = inf, e = -inf;
			for (int k = j; k < c; ++k) {
				d = min(d, mat[i][k]);
				e = max(e, mat[i][k]);
				Max[i][j][k] = e;
				Min[i][j][k] = d;
				//cout<<Max[i][j][k]<<" "<<Min[i][j][k]<<endl;
			}
		}
	}

}

int get(int r) {

	int len = 0, start = 0;
	for (int i = 0; i < r; ++i) {
		if (temp[i] == true)
			continue;
		else {
			len = max(len, i - start);
			start = i + 1;
		}
	}
	len = max(len, r - start);
	for (int i = 0; i < r; ++i)
		temp[i] = true;
	return len;
}
int solve(int r, int c, int k) {

	int ans = 0;
	for (int l = 0; l < c; ++l) {
		for (int ri = 0; ri < c; ++ri) {
			for (int i = 0; i < r; ++i)
				temp[i] = true;
			for (int i = 0; i < r; ++i) {
				if (Max[i][l][ri] - Min[i][l][ri] > k)
					temp[i] = false;
				//cout<<Max[i][l][ri]<<" "<<Min[i][l][ri]<<" "<<i + 1<<" "<<l + 1<<" "<<ri + 1<<endl;
			}
			int len = get(r);
			ans = max(ans, (ri - l + 1) * len);
			//cout<<len<<" "<<(ri - l + 1) * len<<endl;
		}
	}
	return ans;
}
int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int r, c, k;
		scanf("%d%d%d", &r, &c, &k);
		for (int j = 0; j < r; ++j)
			for (int k = 0; k < c; ++k)
				scanf("%d", mat[j] + k);
		calc(r, c);
		printf("Case #%d: %d\n", i + 1, solve(r, c, k));
	}
	return 0;
}

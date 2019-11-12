#include <iostream>
#include <vector>

#define N 100000
using namespace std;

int row[N], col[N];
vector <int> mat[N];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, m, ans = 1e9;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			row[i] = m;
			mat[i].clear();
		}
		for (int i = 0; i < m; ++i)
			col[i] = n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char c;
				scanf(" %c", &c);
				mat[i].push_back(1);
				if (c == '.') {
					row[i]--, col[j]--;
					mat[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int r = 0;
				if (mat[i][j] == 1)
					r = 1;
				ans = min(ans, n + m - 1 - row[i] - col[j] + r);
				//cout<<row[i]<<" "<<col[j]<<"\t";
			}
			//cout<<endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}

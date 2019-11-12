#include <iostream>

using namespace std;

int ans[1005][5];

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < 5; ++j)
			ans[i][j] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			scanf(" %c", &c);
			ans[j][c - 'A']++;
		}
	}
	long long an = 0;
	for (int i = 0; i < m; ++i) {
		int score;
		scanf("%d", &score);
		int mx = -1;
		for (int j = 0; j < 5; ++j)
			mx = max(mx, ans[i][j]);
		an += score * mx;
	}
	cout<<an<<endl;
	return 0;
}

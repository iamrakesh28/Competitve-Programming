#include <bits/stdc++.h>

using namespace std;

char grid[105][105];

int main()
{
	int n, m, cnt = 0;
	scanf("%d%d",&n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s",grid + i);
	// horizontal
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 3; ++j)
			if (grid[i][j] == 's' && grid[i][j + 1] == 'a' && grid[i][j + 2] == 'b' && grid[i][j + 3] == 'a')
				cnt++;
	}
	// vertical
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n - 3; ++j)
			if (grid[j][i] == 's' && grid[j + 1][i] == 'a' && grid[j + 2][i] == 'b' && grid[j + 3][i] == 'a')
				cnt++;
	}
	// diagonal1
	for (int k = 0; k < n - 3; ++k)
		for (int i = k, j = 0; i < n - 3 && j < m - 3; ++i, ++j) {
				if (grid[i][j] == 's' && grid[i + 1][j + 1] == 'a' && grid[i + 2][j + 2] == 'b' && grid[i + 3][j + 3] == 'a')
					cnt++;
	}
	
	for (int k = 1; k < m - 3; ++k)
		for (int i = 0, j = k; i < n - 3 && j < m - 3; ++i, ++j) {
				if (grid[i][j] == 's' && grid[i + 1][j + 1] == 'a' && grid[i + 2][j + 2] == 'b' && grid[i + 3][j + 3] == 'a')
					cnt++;
	}
	// diagonal2
	for (int k = n - 1; k >= 3; --k)
		for (int i = k, j = 0; i - 3 >= 0 && j < m - 3; ++j, --i) {
				if (grid[i][j] == 's' && grid[i - 1][j + 1] == 'a' && grid[i - 2][j + 2] == 'b' && grid[i - 3][j + 3] == 'a')
					cnt++;
	}
	for (int k = 1; k < m - 3; ++k)
		for (int i = n - 1, j = k; i - 3 >= 0 && j < m - 3; ++j, --i) {
				if (grid[i][j] == 's' && grid[i - 1][j + 1] == 'a' && grid[i - 2][j + 2] == 'b' && grid[i - 3][j + 3] == 'a')
					cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}

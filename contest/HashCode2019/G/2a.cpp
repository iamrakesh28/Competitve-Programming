#include <bits/stdc++.h>

using namespace std;

int col[105];
char grid[105][105];

int main()
{
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int c, row = 1;
		scanf("%d", &c);
		for (int j = 0; j < c; ++j) {
			scanf("%d",col + j);
			row = max(row, col[j]);
		}
		if (col[0] == 0 || col[c - 1] == 0) {
			printf("Case #%d: IMPOSSIBLE\n",i + 1);
			continue;
		}
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < c; ++k)
				grid[j][k] = '.';
		}
		int l =  0, r = c - 1;
		for (int j = 0; j < c; ++j) {			
			if (col[j]) {
				if (l == j) {
					int req = col[j] - 1;
					l++;
					while (req) {
						for (int k = 0; k < req; ++k)
							grid[k][l] = '/';
						l++;
						req--;
					}
				}
				else if (l < j) {
					int req = 1;
					//cout<<j<<" "<<l<<endl;
					while (req <= col[j] && l < j) {
						for (int k = 0; k < req; ++k)
							grid[k][l] = '[';
						l++;
						req++;
					}
					if (req < col[j]) {
						l++;
						req++;
						req = col[j] - req;
						while (req) {
							for (int k = 0; k < req; ++k)
								grid[k][l] = '/';
								l++;
								req--;
						}
					}
					else
						l++;
				}
				else {
					int req = col[j], c1 = l - 1, cnt = 1;
					while (c1 > j) {
						for (int k = 0; k < req; ++k)
							grid[cnt][l] = '/';
						cnt++;
						c1--;
					}
					while (req) {
						for (int k = 0; k < req; ++k)
							grid[k][l] = '/';
						l++;
						req--;
					}
				}
			}
		}
		printf("Case #%d: %d\n",i + 1, row);
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < c; ++k)
				if (grid[j][k] == '[')
					printf("\\");
				else
					printf("%c",grid[j][k]);
			printf("\n");
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

char mat[55][55];
int dx[] = {1,1,1,2}, dy[] = {-1,0,1,0};
bool valid(int i, int j, int n)
{
	if (i >= 0 && j >= 0 && i < n && j < n)
		return true;
	return false;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%s",mat[i]);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if (mat[i][j] == '.') {
				mat[i][j] = '#';
				for(int k = 0; k < 4; ++k) {
					bool check = valid(i + dx[k],j + dy[k], n) && mat[i + dx[k]][j + dy[k]] == '.';
					if (check == false) {
						printf("NO\n");
						return 0;
					}
					mat[i + dx[k]][j + dy[k]] = '#';
				}
				
			}
		}
	}
	printf("YES\n");
	return 0;
}

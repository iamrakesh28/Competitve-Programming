#include <iostream>

using namespace std;

const int N = 305;
int grid[N][N], dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m) {
  if (i >= 0 && j >=0 && i < n && j < m)
    return true;
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
	scanf("%d", grid[i] + j);
    bool poss = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	int cnt = 0;
	for (int d = 0; d < 4; ++d)
	  if (valid(i + dr[d], j + dc[d], n, m))
	    cnt++;
	if (cnt < grid[i][j])
	  poss = false;
	grid[i][j] = cnt;
      }
    }
    if (poss == false) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; j++)
	printf("%d ", grid[i][j]);
      puts("");
    }
  }
  return 0;
}

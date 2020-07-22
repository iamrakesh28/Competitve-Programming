#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e3 + 5;
char mat[N][N];
int n, m, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
bool visit[N][N];

bool valid(int i, int j) {
  if (i >= 0 && j >= 0 && i < n && j < m)
    return true;
  return false;
			   
}

void bfs(int i, int j) {
  queue <pair <int, int>> s;
  visit[i][j] = true;
  s.push({i, j});
  while (s.size()) {
    auto it = s.front();
    s.pop();
    int a = it.first, b = it.second;
    for (int i = 0; i < 4; ++i) {
      if (valid (a + dr[i], b + dc[i]) && visit[a + dr[i]][b + dc[i]] == false) {
	visit[a + dr[i]][b + dc[i]] = true;
	s.push({a + dr[i], b + dc[i]});
      }
    }
  }
}

int main() {
  int row = 0, col = 0, cnt;
  scanf("%d%d", &n, &m);
  memset(visit, false, sizeof visit);
  for (int i = 0; i < n; ++i)
    scanf("%s", mat[i]);
  for (int i = 0; i < n; ++i) {
    cnt = 0;
    for (int j = 0; j < m; ++j)
      if (mat[i][j] == '#')
	cnt++;
    if (cnt == 0)
      row++;
  }

  for (int i = 0; i < m; ++i) {
    cnt = 0;
    for (int j = 0; j < n; ++j)
      if (mat[j][i] == '#')
	cnt++;
    if (cnt == 0)
      col++;
  }

  if ((row == 0 && col) || (row && col == 0)) {
    puts("-1");
    return 0;
  }
  int f = 1;
  for (int i = 0; i < n; ++i) {
    cnt = 0;
    if (mat[i][0] == '#')
      cnt++;
    for (int j = 1; j < m; ++j) {
      if (mat[i][j] == '#' && mat[i][j - 1] == '.')
	cnt++;
    }
    if (cnt >= 2) {
      f = -1;
      break;
    }
  }

  for (int i = 0; i < m; ++i) {
    cnt = 0;
    if (mat[0][i] == '#')
      cnt++;
    for (int j = 1; j < n; ++j) {
      if (mat[j][i] == '#' && mat[j - 1][i] == '.')
	cnt++;
    }
    if (cnt >= 2) {
      f = -1;
      break;
    }
  }
  if (f == -1) {
    puts("-1");
    return 0;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (mat[i][j] == '.')
	visit[i][j] = true;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (visit[i][j] == false) {
	ans++;
	bfs(i, j);
      }
  }
  printf("%d\n", ans);
  return 0;
}

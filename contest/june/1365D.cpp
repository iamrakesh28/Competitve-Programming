#include <iostream>
#include <queue>

using namespace std;

const int N = 55;

char mat[N][N];
bool visit[N][N];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m) {
  if (i >= 0 && j >= 0 && i < n && j < m)
    return true;
  return false;
}

int solve(int i, int j, int n, int m) {
  queue <pair <int, int>> q;
  int pos = 1;
  q.push({i, j});
  visit[i][j] = true;
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int r = u.first + dr[d], c = u.second + dc[d];
      if (valid(r, c, n, m) && visit[r][c] == false) {
	visit[r][c] = true;
	if (mat[r][c] == 'G')
	  pos = -1;
	else if (mat[r][c] == 'B')
	  q.push({r, c});
	else if (mat[r][c] == '.')
	  mat[r][c] = '#';
      }
    }
  }
  return pos;
}

void bfs(int n, int m) {
  queue <pair <int, int>> q;
  q.push({n - 1, m - 1});
  visit[n - 1][m - 1] = true;
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int r = u.first + dr[d], c = u.second + dc[d];
      if (valid(r, c, n, m) && visit[r][c] == false) {
	visit[r][c] = true;
	q.push({r, c});
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
      scanf("%s", mat[i]);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (mat[i][j] == '#')
	  visit[i][j] = true;
	else
	  visit[i][j] = false;
      }
    }
    int pos = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (visit[i][j] == false && mat[i][j] == 'B')
	  pos = solve(i, j, n, m);
	if (pos == -1)
	  break;
      }
      if (pos == -1)
	break;
    }
    if (pos == -1) {
      puts("No");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (mat[i][j] == '#')
	  visit[i][j] = true;
	else
	  visit[i][j] = false;
      }
    }
    if (mat[n - 1][m - 1] != '#')
      bfs(n, m);
    pos = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (mat[i][j] == 'G' && visit[i][j] == false)
	  pos = -1;
      }
    }
    if (pos == -1) {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}

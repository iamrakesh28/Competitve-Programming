#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3 + 5;
char maze[N][N];
bool visit[N][N];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

struct Guard {
  int dist, r, c;
};

void bfs_guard(int r, int c, int di) {

  queue <Guard> q;
  q.push({0, r, c});
  visit[r][c] = true;
  
  while (q.size()) {
    Guard u = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d) {
      int r = dr[d] + u.r, c = dc[d] + u.c;
      if (visit[r][c])
        continue;
      if (u.dist + 1 <= di) {
        visit[r][c] = true;
        q.push({u.dist + 1, r, c});
      }
    }
  }
  
  return;
}

int find_path(int r, int c) {

  queue <Guard> q;
  q.push({0, r, c});
  visit[r][c] = true;
  
  while (q.size()) {
    Guard u = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d) {
      int r = dr[d] + u.r, c = dc[d] + u.c;
      if (visit[r][c])
        continue;
      if (maze[r][c] == 'E')
        return u.dist + 1;
      
      visit[r][c] = true;
      q.push({u.dist + 1, r, c});
    }
  }
  
  return -1;
}

int main() {

  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", maze[i]);
  }

  pair <int, int> start, end;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == '#')
        visit[i][j] = true;
      else
        visit[i][j] = false;

      if (maze[i][j] == 'S')
        start = {i, j};
      else if (maze[i][j] == 'E')
        end = {i, j};
    }
  }
  
  for (int i = 0; i < k; ++i) {
    int x, y, d;
    scanf("%d%d%d", &x, &y, &d);
    bfs_guard(x - 1, y - 1, d);
  }

  if (
      visit[start.first][start.second] ||
      visit[end.first][end.second]
      ) {
    puts("IMPOSSIBLE");

    return 0;
  }

  int dist = find_path(start.first, start.second);

  if (dist < 0) {
    puts("IMPOSSIBLE");
    return 0;
  }

  printf("%d\n", dist);
  return 0;
}

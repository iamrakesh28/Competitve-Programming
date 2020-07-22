#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e3 + 5, inf = 1e9;

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int dist1[N][N], dist2[N][N];
bool visit[N][N];
pair <int, int> par[N][N];
char mat[N][N];

bool valid(int i, int j, int n, int m) {
  if (i >= 0 && i < n && j >= 0 && j < m)
    return true;
  return false;
}

void bfs1(int n, int m) {

  queue <pair <int, int>> q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (mat[i][j] == '*') {
	q.push({i, j});
	dist1[i][j] = 0;
	visit[i][j] = true;
      }
      else if (mat[i][j] == '#' || mat[i][j] == 'T') {
	visit[i][j] = true;
	dist1[i][j] = inf;
      }
      else {
	visit[i][j] = false;
	dist1[i][j] = inf;
      }
  
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int r, c;
      r = dr[d] + u.first, c = dc[d] + u.second;
      if (valid(r, c, n, m) && visit[r][c] == false) {
	visit[r][c] = true;
	dist1[r][c] = dist1[u.first][u.second] + 1;
	q.push({r, c});
      }
    }
  }
  return;
}

void bfs2(pair <int, int> S, int n, int m) {

  queue <pair <int, int>> q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (mat[i][j] == '#')
	visit[i][j] = true;
      else
	visit[i][j] = false;

  visit[S.first][S.second] = true;
  q.push(S);
  dist2[S.first][S.second] = 0;
  
  while (q.size()) {
    auto u = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int r, c, t;
      r = dr[d] + u.first, c = dc[d] + u.second;
      t = dist2[u.first][u.second] + 1;
      if (valid(r, c, n, m) && visit[r][c] == false && t < dist1[r][c]) {
	visit[r][c] = true;
	dist2[r][c] = t;
	par[r][c] = {u.first, u.second};
	q.push({r, c});
      }
    }
  }
  return;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  queue <pair <int, int>> q;
  pair <int, int> S, T;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char ch;
      scanf(" %c", &ch);
      if (ch == 'S')
	S = {i, j};
      else if(ch == 'T')
	T = {i, j};
      mat[i][j] = ch;
    }
  bfs1(n, m);
  //cout<<dist1[T.first][T.second]<<endl;
  bfs2(S, n, m);

  //path find

  if (visit[T.first][T.second] == false) {
    puts("-1");
    return 0;
  }
  vector <pair <int, int>> ans;
  pair <int, int> city = T;
  ans.push_back(city);
  while (city != S) {
    city = par[city.first][city.second];
    ans.push_back(city);
  }
  printf("%d\n", ans.size());
  reverse(ans.begin(), ans.end());
  for (auto it : ans)
    printf("%d %d\n", it.first + 1, it.second + 1);
  return 0;
}

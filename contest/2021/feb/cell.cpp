#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20, INF = 1e9;
int dist[MAX][MAX];

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int cellToNum(int i, int j, int m) { return i * m + j; }

pair <int, int> numToCell(int num, int m) { return {num / m, num % m}; }

bool valid(int r, int c, int n, int m) {

  if (r >= 0 && c >= 0 && r < n && c < m)
    return true;
  return false;
}

void bfs(int num, int s, int n, int m) {

  for (int i = 0; i < n * m; ++i) {
    dist[s][i] = INF;
  }
  dist[s][s] = 0;
  queue <int> q;
  q.push(s);

  while (q.size()) {
    int u = q.front();
    q.pop();
    pair <int, int> cell = numToCell(u, m);
    // cout << cell.second + 1 << " " << cell.first + 1 << endl;

    for (int d = 0; d < 4; ++d) {
      int r = dr[d] + cell.first, c = dc[d] + cell.second;
      int loc = cellToNum(r, c, m);
      if (valid(r, c, n, m) && dist[s][loc] >= INF) {
        if (num & (1 << loc)) {
          q.push(loc);
          dist[s][loc] = dist[s][u] + 1;
        }
      }
    }
  }

  return;
}

int distance(int i, int j, int m) {

  pair <int, int> pos1 = numToCell(i, m);
  pair <int, int> pos2 = numToCell(j, m);

  int d = abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
  return d;
}

bool multiBfs(int num, int n, int m) {

  int size = n * m;
  for (int i = 0; i < size; ++i) {
    if (num & (1 << i)) {
      bfs(num, i, n, m);
    }
  }

  bool res = true;
  for (int i = 0; i < size; ++i) {
    if (num & (1 << i)) {
      for (int j = i + 1; j < size; ++j) {
        if (num & (1 << j)) {
          int d1 = distance(i, j, m);
          // cout << d1 << " " << dist[i][j] << endl;
          if (d1 != dist[i][j])
            res = false;
        }
      }
    }
  }

  return res;
}

int main() {

  int n, t;
  scanf("%d%d", &n, &t);

  int M = 0, N = 0;
  vector <pair <int, int>> locs;
  for (int i = 0; i < n; ++i) {
    int xi, yi;
    scanf("%d%d", &xi, &yi);
    M = max(M, xi);
    N = max(N, yi);
    locs.push_back({yi - 1, xi - 1});
  }

  int set_size = INF, cnt = 0;
  int s = 0;
  for (auto it : locs) {
    int num = cellToNum(it.first, it.second, M);
    s = s | (1 << num);
  }

  int size = M * N;
  for (int i = 0; i < (1 << size); ++i) {

    int temp = 0;
    if ((i & s) != s)
      continue;

    for (int j = 0; j < size; ++j) {
      if (i & (1 << j)) {
        temp++;
      }
    }


    bool found = multiBfs(i, N, M);

    if (found) {

      if (set_size > temp) {
        set_size = temp;
        cnt = 1;
      }
      else if (set_size == temp)
        cnt++;
    }
  }

  if (t == 1)
    printf("%d %d\n", set_size, cnt);
  else
    printf("%d\n", set_size);
  return 0;
}

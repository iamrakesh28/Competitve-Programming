#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 505;
int par[N << 1], _size[N << 1];
int A[N][N], B[N][N];

struct Error {
  int b, r, c;
};

vector <pair<int, pair<int, int>>> bug;

int find(int u) {
  if (u == par[u])
    return u;
  par[u] = find(par[u]);
  return par[u];
}

bool join(int u, int v) {
  u = find(u), v = find(v);

  if (u == v)
    return false;

  if (_size[u] > _size[v]) {
    _size[u] += _size[v];
    par[v] = u;
  }
  else {
    _size[v] += _size[u];
    par[u] = v;
  }
  
  return true;
}

void reset(int n) {

  for (int i = 0; i < (n << 1); ++i) {
    par[i] = i;
    _size[i] = 1;
  }

  bug.clear();
  return;
}

bool comparator(Error &a, Error &b) {
  if (a.b != b.b)
    return a.b < b.b;

  return true;
}

int main() {

  int t;
  scanf("%d", &t);

  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%d", &n);
    
    reset(n);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%d", A[i] + j);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", B[i] + j);

        if (A[i][j] == -1) {
          bug.push_back({B[i][j], {i, j}});
        }
      }
    }

    int ri, cj;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &ri);
    }

    for (int i = 0; i < n; ++i) {
      scanf("%d", &cj);
    }

    sort(bug.begin(), bug.end());
    reverse(bug.begin(), bug.end());
    
    int cost = 0;
    for (auto p : bug) {
      int u = p.second.first, v = p.second.second + n;
      if (join(u, v) == false) {
        cost += p.first;
      }
    }

    printf("Case #%d: %d\n", q + 1, cost);
  }
  
  return 0;
}

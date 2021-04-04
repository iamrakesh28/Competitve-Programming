#include <iostream>
#include <map>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;
int A[N], lose[N];
map <pair<int, int>, int> query;

void initialize(int m) {

  query.clear();
  memset(lose, 0, sizeof(int) * (m + 1));

  return;
}

void update(int l, int r, int cnt, int m) {

  int len = l + r;
  for (int i = 0; i <= m; i += len) {
    lose[i] += cnt;
    if (i + l <= m)
      lose[i + l] -= cnt;
  }
  return;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, q, m, wins;
    scanf("%d%d%d", &n, &q, &m);

    for (int i = 0; i < n; ++i) {
      scanf("%d", A + i);
    }
    
    initialize(m);
    wins = q;

    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--, r--;

      auto find = query.find(make_pair(l, r));
      if (find == query.end())
        query[make_pair(l, r)] = 1;
      else
        query[make_pair(l, r)] = find -> second + 1;
    }

    
    for (auto it : query) {
      int l = it.first.first, r = it.first.second, cnt = it.second;
      int al = A[l], ar = A[r];
      update(al, ar, cnt, m);
    }

    for (int i = 1; i <= m; ++i) {
      lose[i] += lose[i - 1];
    }
    
    int min_lose = 1e9;
    for (int i = 1; i <= m; ++i) {
      // cout << i << " " << lose[i] << endl;
      min_lose = min(min_lose, lose[i]);
    }

    printf("%d\n", wins - min_lose);
  }
  
  return 0;
}

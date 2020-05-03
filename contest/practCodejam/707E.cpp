#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 2e3;
long long bit[N][N], gar[N][N];
vector <pair <int, pair <int, int>>> light[N];
vector <int> req;
int n, m, k, on[N];

struct Query {
  int x1, y1, s;
  int x2, y2;
} query[1000000];

long long sum(int x, int y) {
  long long ret = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
      ret += bit[i][j];
  return ret;
}

void update(int x, int y, int delta) {
  for (int i = x; i < n; i = i | (i + 1))
    for (int j = y; j < m; j = j | (j + 1))
      bit[i][j] += delta;
}

int main() {
  int q;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int len;
    scanf("%d", &len);
    on[i] = 1;
    for (int j = 0; j < len; ++j) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      light[i].push_back({x - 1, {y - 1, w}});
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    char str[7];
    scanf("%s", str);
    if (strcmp(str, "SWITCH") == 0) {
      int g;
      scanf("%d", &g);
      query[i].s = g - 1;
    }
    else {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      query[i].s = -1;
      query[i].x1 = x1 - 1;
      query[i].x2 = x2 - 1;
      query[i].y1 = y1 - 1;
      query[i].y2 = y2 - 1;
      req.push_back(i);
    }
  }

  for (int i = 0; i < k; ++i) {
    for (auto it : light[i])
      update(it.first, it.second.first, it.second.second);
    int j = 0;
    for (int it : req) {
      int x1 = query[it].x1;
      int x2 = query[it].x2;
      int y1 = query[it].y1;
      int y2 = query[it].y2;
      long long Sum = sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
      gar[i][j++] = Sum;
    }
    for (auto it : light[i])
      update(it.first, it.second.first, -it.second.second);
  }
  int j = 0;
  for (int i = 0; i < q; ++i) {
    if (query[i].s != -1)
      on[query[i].s] = 1 - on[query[i].s];
    else {
      long long ans = 0;
      for (int r = 0; r < k; ++r)
	if (on[r])
	  ans += gar[r][j];
      j++;
      printf("%lld\n", ans);
    }
  }
  return 0;
}

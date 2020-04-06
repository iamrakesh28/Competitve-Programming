#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5, inf = 1e8;
int A[N], cnt[N], temp[N];
set <int> typePos[N];
pair <int, int> tree[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr)
    tree[v] = {temp[tl], temp[tl]};
  else {
    int tm = (tl + tr) >> 1;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    tree[v].second = tree[2 * v + 1].second + tree[2 * v + 2].second;
    tree[v].first = max(tree[2 * v + 1].first, tree[2 * v + 2].first + tree[2 * v + 1].second);
  }
}

pair <int, int> query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {inf, inf};
  if (l == tl && r == tr)
    return tree[v];
  int tm = (tl + tr) >> 1;
  auto left = query(2 * v + 1, tl, tm, l, min(tm, r));
  auto right = query(2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
  if (left.first == inf)
    return right;
  if (right.first == inf)
    return left;
  pair <int, int> ret;
  ret.second = left.second + right.second;
  ret.first = max(left.first, right.first + left.second);
  return ret;
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr)
    tree[v] = {val, val};
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      update(2 * v + 1, tl, tm, pos, val);
    else
      update(2 * v + 2, tm + 1, tr, pos, val);
    tree[v].second = tree[2 * v + 1].second + tree[2 * v + 2].second;
    tree[v].first = max(tree[2 * v + 1].first, tree[2 * v + 2].first + tree[2 * v + 1].second);
  }
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int j = 0; j < n; ++j)
      scanf("%d", A + j);
    for (int j = 0; j < N; ++j)
      typePos[j].clear(), cnt[j] = 0;
    
    for (int j = 0 ; j < n; ++j) {
      cnt[A[j] - 1]++;
      if (cnt[A[j] - 1] <= s)
	temp[j] = 1;
      else {
	typePos[A[j] - 1].insert(j);
	if (cnt[A[j] - 1] == s + 1)
	  temp[j] = -s;
	else
	  temp[j] = 0;
      }
    }
    build(0, 0, n - 1);
    int ans = query(0, 0, n - 1, 0, n - 1).first;
    for (int j = 1; j < n; ++j) {
      int type = A[j - 1] - 1;
      if (typePos[type].size()) {
	auto it = typePos[type].begin();
	typePos[type].erase(it);
	update(0, 0, n - 1, *it, 1);
      }
      if (typePos[type].size()) {
	auto it = typePos[type].begin();
	typePos[type].erase(it);
	update(0, 0, n - 1, *it, -s);
      }
      ans = max(ans, query(0, 0, n - 1, j, n - 1).first);
    }

    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}

#include <iostream>

using namespace std;

const int N = 1e5, inf = -1e9;
int A[N];
pair <int, int> tree[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = {A[tl], A[tl]};
    return;
  }
  int mid = (tl + tr) >> 1;
  build(2 * v + 1, tl, mid);
  build(2 * v + 2, mid + 1, tr);
  tree[v].second = tree[2 * v + 1].second + tree[2 * v + 2].second;
  tree[v].first = max(tree[2 * v + 1].first, tree[2 * v + 2].first + tree[2 * v + 1].second);
}

pair <int, int> query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {inf, 0};
  if (tl == l && tr == r)
    return tree[v];
  int tm = (tl + tr) >> 1;
  auto left = query(2 * v + 1, tl, tm, l, min(tm, r));
  auto right = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
  if (left.first == inf)
    return right;
  if (right.first == inf)
    return left;
  pair <int, int> ret;
  ret.second = left.second + right.second;
  ret.first = max(left.first, right.first + left.second);
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", A + i);
  build(0, 0, n - 1);
  auto it = query(0, 0, n - 1, 0, 4);
  cout<<it.first<<" "<<it.second<<endl;
  return 0;
}

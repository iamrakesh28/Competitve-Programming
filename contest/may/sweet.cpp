#include <iostream>

using namespace std;

typedef long long ll;
struct Node {
  int len;
  ll ans1, ans2, sum1, sum2;
};

const int N = 2e5 + 5;
Node t[N << 2];
int A[N];

void help(int v, int tm, int tl) {
  int len = t[2 * v + 1].len;
  if (len & 1) {
    t[v].ans1 = t[2 * v + 1].ans1 + t[2 * v + 2].ans2 + len * t[2 * v + 2].sum2;
    t[v].ans2 = t[2 * v + 1].ans2 + t[2 * v + 2].ans1 + len * t[2 * v + 2].sum1;
    t[v].sum1 = t[2 * v + 1].sum1 + t[2 * v + 2].sum2;
    t[v].sum2 = t[2 * v + 1].sum2 + t[2 * v + 2].sum1;
  }
  else {
    t[v].ans1 = t[2 * v + 1].ans1 + t[2 * v + 2].ans1 + len * t[2 * v + 2].sum1;
    t[v].ans2 = t[2 * v + 1].ans2 + t[2 * v + 2].ans2 + len * t[2 * v + 2].sum2;
    t[v].sum1 = t[2 * v + 1].sum1 + t[2 * v + 2].sum1;
    t[v].sum2 = t[2 * v + 1].sum2 + t[2 * v + 2].sum2;
  }
  t[v].len = t[2 * v + 1].len + t[2 * v + 2].len;
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = {1, A[tl], -A[tl], A[tl], -A[tl]};
    return;
  }
  int tm = tl + tr >> 1;
  build(2 * v + 1, tl, tm);
  build(2 * v + 2, tm + 1, tr);
  int len = tm - tl + 1;
  help(v, tm, tl);
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    A[tl] = val;
    t[v] = {1, A[tl], -A[tl], A[tl], -A[tl]};
    return;
  }
  int tm = tl + tr >> 1;
  if (pos <= tm)
    update(2 * v + 1, tl, tm, pos, val);
  else
    update(2 * v + 2, tm + 1, tr, pos, val);
  help(v, tm, tl);
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {0, 0, 0, 0, 0};
  if (l == tl && r == tr)
    return t[v];
  int tm = tl + tr >> 1;
  Node node, node1, node2;
  node1 = query(2 * v + 1, tl, tm, l, min(tm, r));
  node2 = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
  int len = node1.len;
  if (len & 1) {
    node.ans1 = node1.ans1 + node2.ans2 + len * node2.sum2;
    node.ans2 = node1.ans2 + node2.ans1 + len * node2.sum1;
    node.sum1 = node1.sum1 + node2.sum2;
    node.sum2 = node1.sum2 + node2.sum1;
  }
  else {
    node.ans1 = node1.ans1 + node2.ans1 + len * node2.sum1;
    node.ans2 = node1.ans2 + node2.ans2 + len * node2.sum2;
    node.sum1 = node1.sum1 + node2.sum1;
    node.sum2 = node1.sum2 + node2.sum2;
  }
  node.len = node1.len + node2.len;
  //cout<<endl<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<node1.ans1<<endl;
  return node;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
      scanf("%d", A + i);
    ll ans = 0;
    build(0, 0, n - 1);
    while (q--) {
      char c;
      int l, r;
      scanf(" %c%d%d", &c, &l, &r);
      if (c == 'U')
	update(0, 0, n - 1, l - 1, r);
      else {
	Node it = query(0, 0, n - 1, l - 1, r - 1);
	ans = ans + it.ans1;
	//cout<<it.ans1<<endl;
      }
    }
    printf("Case #%d: %lld\n", j + 1, ans);
  }
  return 0;
}

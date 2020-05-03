#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5, size = 700;
int a[N], prex[N], xo[N * 10];
ll ans[N];

struct Query {
  int l, r, block, id;
} query[N];

bool compare(Query &a, Query &b) {
  if (a.block != b.block)
    return a.block < b.block;
  return a.r < b.r;
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  prex[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    prex[i + 1] = prex[i] ^ a[i];
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    query[i] = {l, r, l / size, i};
  }
  sort(query, query + m, compare);
  int curl = 0, curr = -1;
  ll as = 0;
  xo[0] = 1;
  /*
  curl = query[0].l, curr = query[0].r;
  for (int i = curl; i <= curr; ++i) {
    int xorr, id;
    id = query[0].id;
    xorr = prex[i + 1] ^ k;
    xo[prex[i + 1]]++;
    as += xo[xorr];
    cout<<as<<endl;
    if (xorr == 0)
      as++;
    ans[id] = as;
  }
  */
  for (int i = 0; i < m; ++i) {
    int l, r, id, xorr, left;
    l = query[i].l, r = query[i].r, id = query[i].id;
    //cout<<l+1<<" "<<r+1<<endl;
    while (curl > l) {
      curl--;
      xorr = prex[curl] ^ k;
      as += xo[xorr];
      xo[prex[curl]]++;
    }
    while (curl < l) {
      xorr = prex[curl] ^ k;
      as -= xo[xorr];
      xo[prex[curl]]--;
      curl++;
    }
    /*
      cout<<curl<<" "<<curr<<" ";
    for (int j = 0; j < 8; ++j)
      cout<<xo[j]<<" ";
    puts("");
    */
    while (curr > r) {
      xorr = prex[curr + 1] ^ k;
      as -= xo[xorr];
      xo[prex[curr + 1]]--;
      curr--;
    }
    while (curr < r) {
      curr++;
      xorr = prex[curr + 1] ^ k;
      as += xo[xorr];
      xo[prex[curr + 1]]++;
    }
    ans[id] = as;
  }
  for (int i = 0; i < m; ++i)
    printf("%lld\n", ans[i]);
  return 0;
}

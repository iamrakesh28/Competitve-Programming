#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

const int N = 5e5 + 5, size = 900;
struct Query {
  int l, r, id, f;
  /*
  bool operator <(Query other) const {
    return make_pair(f, r) <
      make_pair(other.f, other.r);
  }
  */
} query[N];

bool compare(Query &a, Query &b) {
  if (a.f != b.f)
    return a.f < b.f;
  return (a.f & 1) ? (a.r > b.r) : (a.r < b.r);
}

int a[N], h[N], freq[N], pans[N];

int main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for (int i = 0; i < m; ++i)
    scanf("%d", h + i);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    query[i] = {l, r, i, l / size};
  }
  sort(query, query + q, compare);
  int ans = 0, curl = 0, curr = -1, dist = 0;
  for (int i = 0; i < q; ++i) {
    int l, r;
    l = query[i].l;
    r = query[i].r;
    while (curl > l) {
      curl--;
      if (freq[a[curl] - 1] == 0)
	dist++;
      freq[a[curl] - 1]++;
      if (freq[a[curl] - 1] == h[a[curl] - 1])
	ans++;
      else if (freq[a[curl] - 1] == h[a[curl] - 1] + 1)
	ans--;
    }
    while (curr < r) {
      curr++;
      if (freq[a[curr] - 1] == 0)
	dist++;
      freq[a[curr] - 1]++;
      if (freq[a[curr] - 1] == h[a[curr] - 1])
	ans++;
      else if (freq[a[curr] - 1] == h[a[curr] - 1] + 1)
	ans--;
    }
    while (curl < l) {
      freq[a[curl] - 1]--;
      if (freq[a[curl] - 1] == 0)
	dist--;
      if (freq[a[curl] - 1] == h[a[curl] - 1])
	ans++;
      else if (freq[a[curl] - 1] == h[a[curl] - 1] - 1)
	ans--;
      curl++;
    }
    while (curr > r) {
      freq[a[curr] - 1]--;
      if (freq[a[curr] - 1] == 0)
	dist--;
      if (freq[a[curr] - 1] == h[a[curr] - 1])
	ans++;
      else if (freq[a[curr] - 1] == h[a[curr] - 1] - 1)
	ans--;
      curr--;
    }
    int id = query[i].id;
    if (ans == dist)
      pans[id] = 1;
    else
      pans[id] = 0;
    //cout<<l+1<<" "<<r+1<<" "<<ans<<" "<<i+1<<endl;
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", pans[i]);
  return 0;
}

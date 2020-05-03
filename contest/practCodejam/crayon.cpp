#include <iostream>
#include <map>
#include <set>

using namespace std;

const int N = 2e5 + 5;
int bitdown[N], bitup[N], d;
set <int> st;
map <int, int> mp;
pair <int, int> seg[N >> 1];
struct Query {
  char c;
  int l, r;
} query[N >> 1];


void update(int *bit, int x, int delta) {
  for (int i = x; i < d; i = i | (i + 1))
    bit[i] += delta;
}

int sum(int *bit, int x) {
  int ret = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1)
    ret += bit[x];
  return ret;
}

void lineadd(int l, int r) {
  update(bitup, l, -1);
  update(bitup, 0, 1);
  if (r + 1 < d)
    update(bitdown, r + 1, 1);
}

void linesub(int l, int r) {
  update(bitup, l, 1);
  update(bitup, 0, -1);
  if (r + 1 < d)
    update(bitdown, r + 1, -1);
}

int main() {
  int n;
  scanf("%d", &n);
  d = 0;
  for (int i = 0; i < n; ++i) {
    char c;
    int l, r;
    scanf(" %c", &c);
    if (c == 'C') {
      scanf("%d", &l);
      query[i].c = c;
      query[i].l = l;
      //st.insert(l);
    }
    else {
      scanf("%d%d", &l, &r);
      query[i].c = c;
      query[i].l = l;
      query[i].r = r;
      st.insert(l);
      st.insert(r);
      if (c == 'D')
	seg[d++] = {l, r};
    }
  }
  d = 0;
  int cur = 0;
  for (int x : st)
    mp.insert({x, d++});
  for (int i = 0; i < n; ++i) {
    char c;
    int l, r;
    c = query[i].c;
    l = query[i].l;
    r = query[i].r;
    if (c == 'D') {
      l = mp.at(l);
      r = mp.at(r);
      lineadd(l, r);
      cur++;
    }
    else if (c == 'Q') {
      l = mp.at(l);
      r = mp.at(r);
      int ans = sum(bitdown, l) + sum(bitup, d - 1) - sum(bitup, r);
      ans = cur - ans;
      printf("%d\n", ans);
    }
    else {
      r = mp.at(seg[l - 1].second);
      l = mp.at(seg[l - 1].first);
      linesub(l, r);
      cur--;
    }
  }
  return 0;
}

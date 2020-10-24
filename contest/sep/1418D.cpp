#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int pi[N];
set <pair <int, pair <int, int>>> seg;
set <int> piles;

void erase(int x) {
  if (piles.size() == 1) {
    piles.erase(x);
    return;
  }
  auto cur = piles.find(x);
  if (cur == piles.begin()) {
    cur++;
    int next = *cur;
    seg.erase(seg.find({next - x + 1, {x, next}}));
    cur--;
    piles.erase(cur);
  }
  else {
    cur++;
    if (cur == piles.end()) {
      cur--, cur--;
      int prev = *cur;
      seg.erase(seg.find({x - prev + 1, {prev, x}}));
      cur++;
      piles.erase(cur);
    }
    else {
      int next = *cur, prev;
      cur--, cur--;
      prev = *cur;
      cur++;
      piles.erase(cur);
      seg.erase(seg.find({next - x + 1, {x, next}}));
      seg.erase(seg.find({x - prev + 1, {prev, x}}));
      seg.insert({next - prev + 1, {prev, next}});
    }
  }
  return;
}

void add(int x) {
    if (piles.size() == 0) {
    piles.insert(x);
    return;
  }
  auto cur = piles.lower_bound(x);
  if (cur == piles.begin()) {
    int next = *cur;
    seg.insert({next - x + 1, {x, next}});
    piles.insert(x);
  }
  else {
    if (cur == piles.end()) {
      cur--;
      int prev = *cur;
      seg.insert({x - prev + 1, {prev, x}});
      piles.insert(x);
    }
    else {
      int next = *cur, prev;
      cur--;
      prev = *cur;
      piles.insert(x);
      seg.erase(seg.find({next - prev + 1, {prev, next}}));
      seg.insert({x - prev + 1, {prev, x}});
      seg.insert({next - x + 1, {x, next}});
    }
  }
  return;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", pi + i);
    piles.insert(pi[i]);
  }
  int prev = -1;
  for (int v : piles) {
    if (prev != -1)
      seg.insert({v - prev + 1, {prev, v}});
    prev = v;
  }
  if (seg.size()) {
    auto last = seg.end();
    last--;
    int len = (*last).first;
    int l = *piles.begin(), r;
    auto it = piles.end();
    it--;
    r = *it;
    printf("%d\n", r - l - len + 1);
  }
  else
    puts("0");
  while (q--) {
    int t, x;
    scanf("%d%d", &t, &x);
    if (t)
      add(x);
    else
      erase(x);
    
    if (seg.size()) {
      auto last = seg.end();
      last--;
      int len = (*last).first;
      int l = *piles.begin(), r;
      auto it = piles.end();
      it--;
      r = *it;
      //cout << r << " " << l << " ";
      printf("%d\n", r - l - len + 1);
    }
    else
      puts("0");
  }
  return 0;
}

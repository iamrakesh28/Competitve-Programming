#include <iostream>
#include <set>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5;
int a[N], t[N << 2], lazy[N << 2], accm[N << 2];
vector <int> mp[10005];
set <int> lucky;

void brute(int i, int x) {
  if (i == 0) {
    lucky.insert(x);
    return;
  }
  brute(i - 1, 10 * x + 4);
  brute(i - 1, 10 * x + 7);
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    if (lucky.find(a[tl]) != lucky.end())
      t[v] = 1;
    else
      t[v] = 0;
    lazy[v] = accm[v] = 0;
  }
  else {
    int tm = tl + tr >> 1;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
    lazy[v] = accm[v] = 0;
  }
}

int lower(int ind, int l) {
  int beg = 0, end = mp[ind].size() - 1, mid, ans = -1;
  while (beg <= end) {
    mid = beg + end >> 1;
    if (mp[ind][mid] >= l) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int upper(int ind, int r) {
  int beg = 0, end = mp[ind].size() - 1, mid, ans = -1;
  while (beg <= end) {
    mid = beg + end >> 1;
    if (mp[ind][mid] <= r) {
      ans = mid;
      beg = mid + 1;
    }
    else
      end = mid - 1;
  }
  return ans;
}

int compute(int l, int r, int val) {
 
  int cnt = 0;
  for (int it : lucky) {
    if (it - val <= 0)
      continue;
    int lc = lower(it - val - 1, l);
    if (lc == -1 || mp[it - val - 1][lc] > r)
      continue;
    int rc = upper(it - val - 1, r);
    if (rc == -1 | mp[it - val - 1][rc] < l)
      continue;
    cnt += (rc - lc + 1);
  }
  return cnt;
}

void push(int v, int tl, int tr) {

  lazy[2 * v + 1] += lazy[v];
  accm[2 * v + 1] += lazy[v];
  int tm = tl + tr >> 1;
  t[2 * v + 1] = compute(tl, tm, accm[2 * v + 1]);
  //cout<<t[2 * v + 1]<<" "<<tl+1<<" "<<tm+1<<" "<<accm[2 * v + 1]<<" : ";
  lazy[2 * v + 2] += lazy[v];
  accm[2 * v + 2] += lazy[v];
  t[2 * v + 2] = compute(tm + 1, tr, accm[2 * v + 2]);
  //cout<<t[2 * v + 2]<<" "<<tm+1<<" "<<tr<<" "<<accm[2 * v + 2]<<"\n";
  lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
  if (l > r)
    return;
  if (l == tl && r == tr) {
    lazy[v] += val;
    accm[v] += val;
    t[v] = compute(tl, tr, accm[v]);
  }
  else {
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    update(2 * v + 1, tl, tm, l, min(tm, r), val);
    update(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
    cout<<tl+1<<" "<<tr+1<<" "<<t[v]<<" "<<v<<endl;
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)  {
    cout<<tl+1<<" "<<tr+1<<" "<<t[v]<<endl;
    return t[v];
  }
  push(v, tl, tr);
  int tm = tl + tr >> 1;
  return query(2 * v + 1, tl, tm, l, min(tm, r)) +
    query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

int main() {

  for (int i = 4; i > 0; i--)
    brute(i, 0);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    mp[a[i] - 1].push_back(i);
  }
  build(0, 0, n - 1);
  while (m--) {
    char s[6];
    int l, r, d;
    scanf("%s%d%d", s, &l, &r);
    if (strcmp(s, "count") == 0) {
      cout<<t[1]<<endl<<endl;
      printf("%d\n", query(0, 0, n - 1, l - 1, r - 1));
    }
    else {
      scanf("%d", &d);
      update(0, 0, n - 1, l - 1, r - 1, d);
    }
  }
  return 0;
}

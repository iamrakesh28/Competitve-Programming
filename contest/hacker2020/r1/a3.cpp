#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
const int N = 1e6 + 5, prime = 1e9 + 7;
ll L[N], H[N], W[N];
ll aL, bL, cL, dL, aH, bH, cH, dH;
ll aW, bW, cW, dW, prevl;
set <pair <ll, pair<ll, ll>>> interval;
map <ll, int> mp;
set <ll> st;
bool mark[N << 2];
int cnt;

struct Node {
  ll lh, rh, l, r, per;
} t[N << 2], arr[N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = arr[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(2 * v + 1, tl, tm);
  build(2 * v + 2, tm + 1, tr);
  t[v] = t[2 * v + 1];
  t[v].r = t[2 * v + 2].r;
}

void push(int v) {
  if (mark[v]) {
    t[2 * v + 1].lh = t[2 * v + 1].rh = t[v].lh;
    t[2 * v + 2].lh = t[2 * v + 2].rh = t[v].lh;
    t[2 * v + 1].per = ((t[2 * v + 1].r - t[2 * v + 1].l + t[v].lh) << 1) % prime;
    t[2 * v + 2].per = ((t[2 * v + 2].r - t[2 * v + 2].l + t[v].lh) << 1) % prime;
    mark[2 * v + 1] = mark[2 * v + 2] = true;
    mark[v] = false;
  }
}
void update(int v, int tl, int tr, int l, int r, ll val) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    t[v].lh = t[v].rh = val;
    t[v].per = ((t[v].r - t[v].l + val) << 1) % prime;
    mark[v] = true;
    return;
  }
  push(v);
  int tm = (tl + tr) >> 1;
  update(2 * v + 1, tl, tm, l, min(r, tm), val);
  update(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val);
  t[v].per = (t[2 * v + 1].per + t[2 * v + 2].per) % prime;
  t[v].lh = t[2 * v + 1].lh;
  t[v].rh = t[2 * v + 2].rh;
  if (t[2 * v + 1].rh > 0 && t[2 * v + 2].lh > 0) {
    ll temp = 2 * min(t[2 * v + 1].rh, t[2 * v + 2].lh);
    temp = temp % prime;
    t[v].per = (t[v].per - temp + prime) % prime;
  }
}

Node query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {-1, -1, -1, -1, -1};
  if (l == tl && tr == r)
    return t[v];
  push(v);
  int tm = (tl + tr) >> 1;
  Node n1 = query(2 * v + 1, tl, tm, l, min(r, tm));
  Node n2 = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);

  if (n1.l == -1)
    return n2;
  if (n2.l == -1)
    return n1;

  Node n3 = n1;
  n3.per = (n3.per + n2.per) % prime;
  n3.r = n2.r;
  n3.rh = n2.rh;

  if (n1.rh > 0 && n2.lh > 0) {
    ll temp = 2 * min(n1.rh, n2.lh);
    temp = temp % prime;
    n3.per = (n3.per - temp + prime) % prime;
  }
  return n3;
}

void compute(int k, int n) {
  ll li, hi, wi;
  for (int i = k; i < n; ++i) {
    li = (aL * L[i - 2]) % dL;
    li = (li + (bL * L[i - 1]) % dL) % dL;
    li = (li + cL) % dL;
    li = li + 1;
    L[i] = li;

    hi = (aH * H[i - 2]) % dH;
    hi = (hi + (bH * H[i - 1]) % dH) % dH;
    hi = (hi + cH) % dH;
    hi = hi + 1;
    H[i] = hi;

    wi = (aW * W[i - 2]) % dW;
    wi = (wi + (bW * W[i - 1]) % dW) % dW;
    wi = (wi + cW) % dW;
    wi = wi + 1;
    W[i] = wi;
  }

  for (int i = 0; i < n; ++i) {
    li = L[i];
    wi = L[i] + W[i];
    st.insert(li);
    st.insert(wi);
  }

  int i = 0;
  for (ll v : st) {
    if (i) {
      mp[prevl] = cnt++;
      arr[cnt - 1] = {0, 0, prevl, v, 0};
      //cout << prev << " " << v << endl;
    }
    prevl = v;
    i++;
  }
  //cout << mp[4] << endl;
  for (i = 0; i < 4 * cnt; ++i)
    mark[i] = false;
  build(0, 0, cnt - 1);
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, k;
    ll pi, ans, prev, next;
    interval.clear();
    mp.clear();
    st.clear();
    cnt = 0;
    scanf("%d%d", &n, &k);
    for (int j = 0; j < k; ++j)
      scanf("%lld", L + j);
    scanf("%lld%lld%lld%lld", &aL, &bL, &cL, &dL);
    for (int j = 0; j < k; ++j)
      scanf("%lld", W + j);
    scanf("%lld%lld%lld%lld", &aW, &bW, &cW, &dW);
    for (int j = 0; j < k; ++j)
      scanf("%lld", H + j);
    scanf("%lld%lld%lld%lld", &aH, &bH, &cH, &dH);
    compute(k, n);

    ans = 1;
    for (int j = 0; j < n; ++j) {
      ll l, r;
      l = mp[L[j]];
      if (L[j] + W[j] == prevl)
	r = cnt - 1;
      else
	r = mp[L[j] + W[j]] - 1;
      //cout << l << " " << r << endl;
      update(0, 0, cnt - 1, l, r, H[j]);
      //Node no = query(0, 0, cnt - 1, l, r);
      //cout << L[j] << " " << L[j] + W[j] << " : ";
      //cout << l << " " << r << " "<< no.l << " " << no.r << endl;
      Node res = query(0, 0, cnt - 1, 0, cnt - 1);
      pi = res.per;
      ans = (ans * pi) % prime;
      //cout << pi << endl;
    }
    //cout << "ans: "<< pi << endl;
    printf("Case #%d: %lld\n", i + 1, ans);
  }
  return 0;
}

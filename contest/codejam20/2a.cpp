#include <iostream>

using namespace std;

typedef long long ll;

const ll inf = 1e18 + 5, END = 2e9;

ll ap(ll a, ll diff, ll n) {
  ll sum = 2 * a + (n - 1) * diff;
  sum = sum * n / 2;
  return sum;
}

ll find(ll req, ll diff, ll start) {
  ll beg = 1, end = END, mid, ans = 0;
  while (beg <= end) {
    mid = beg + end >> 1;
    ll sum = ap(start, diff, mid);
    if (sum <= req) {
      ans = mid;
      beg = mid + 1;
    }
    else
      end = mid - 1;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    ll L, R, l, r, n = 0;
    scanf("%lld%lld", &L, &R);
    l = L;
    r = R;
    if (r > l) {
      ll cnt = find(r - l - 1, 1, 1);
      ll sum = ap(1, 1, cnt + 1), start = cnt + 3;
      n = cnt + 1;
      if (sum > r) {
	sum = ap(1, 1, cnt);
	start--;
	n--;
      }
      r = r - sum;
      cnt = find(r, 2, start);
      n += cnt;
      sum = ap(start, 2, cnt);
      r = r - sum;
      //l
      cnt = find(l, 2, start - 1);
      // cout<<cnt<<endl;
      n += cnt;
      sum = ap(start - 1, 2, cnt);
      l = l - sum;
    }
    else {
      ll cnt = find(l - r, 1, 1);
      ll sum = ap(1, 1, cnt + 1), start = cnt + 3;
      n = cnt + 1;
      if (sum > l) {
	start--;
	sum = ap(1, 1, cnt);
	n--;
      }
      l = l - sum;
      //cout<<cnt<<" "<<l<<endl;
      cnt = find(l, 2, start);
      n += cnt;
      sum = ap(start, 2, cnt);
      l = l - sum;
      cnt = find(r, 2, start - 1);
      n += cnt;
      sum = ap(start - 1, 2, cnt);
      r = r - sum;
    }
    printf("Case #%d: %lld %lld %lld\n", i + 1, n, l, r);
  }
  return 0;
}

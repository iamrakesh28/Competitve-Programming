#include <iostream>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
typedef long long ll;
int w[N];

ll cost(int W, ll val, int n) {
  ll ans = 0;
  for (int i = 0; i < W; ++i) {
    ll temp;
    if (val > w[i]) {
      temp = val - w[i];
      temp = min(temp, n - val + w[i]);
    }
    else {
      temp = w[i] - val;
      temp = min(temp, n - w[i] + val);
    }
    ans += temp;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int W, n;
    scanf("%d%d", &W, &n);
    for (int i = 0; i < W; ++i)
      scanf("%d", w + i);
    int beg = 1, end = n, mid, spin;
    ll cm, cn, cb, ans = inf;
    
    while (beg <= end) {
      mid = (beg + end) >> 1;
      cm = cost(W, mid, n);
      cn = cb = inf;
      if (mid + 1 <= n)
	cn = cost(W, mid + 1, n);
      if (mid - 1 >= 1)
	cb = cost(W, mid - 1, n);
      ans = min(ans, cm);
      //cout << mid << " " << cm << " " << cn << " " << cb << endl;
      if (cm > cn)
	beg = mid + 1;
      else if (cm > cb)
	end = mid - 1;
      else {
	if (cn < cb)
	  beg = mid + 1;
	else
	  end = mid - 1;
      }
    }
    mid = n;
    beg = 1, end = n;
    while (beg <= end) {
      cm = cost(W, mid, n);
      cn = cb = inf;
      if (mid + 1 <= n)
	cn = cost(W, mid + 1, n);
      if (mid - 1 >= 1)
	cb = cost(W, mid - 1, n);
      ans = min(ans, cm);
      //cout << mid << " " << cm << " " << cn << " " << cb << endl;
      if (cm > cn)
	beg = mid + 1;
      else if (cm > cb)
	end = mid - 1;
      else {
	if (cn < cb)
	  beg = mid + 1;
	else if (cn < cb)
	  end = mid - 1;
	else
	  beg = mid + 1;
      }
      mid = (beg + end) >> 1;
    }
    printf("Case #%d: %lld\n", q + 1, ans);
  } 
  return 0;
}

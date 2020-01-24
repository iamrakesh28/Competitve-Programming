#include <iostream>
#include <climits>

// #define debug

typedef long long ll;
using namespace std;

const int N = 1e5;
int arr[N], mn, mx, n;
ll k;

ll calc(int l, int r) {
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < l)
      cnt += (l - arr[i]);
    if (arr[i] > r)
      cnt += (arr[i] - r);
  }
  return cnt;
}

bool solve(int diff) {
  int beg = mn, end = mx, mid, l, r;
  ll dk;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    l = mid - diff / 2;
    r = l + diff;
    dk = calc(l, r);
    if (dk <= k)
      return true;
    if (calc(l + 1, r + 1) <= dk)
      beg = mid + 1;
    else
      end = mid - 1;
  }
  return false;
}

int main() {

  #ifdef debug
     freopen("testcase", "r", stdin);
  #endif
     scanf("%d%lld", &n, &k);
  mn = INT_MAX, mx = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    mn = min(mn, arr[i]);
    mx = max(mx, arr[i]);
  }
  
  int beg = 0, end = mx - mn, mid, ans = mx - mn;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    if (solve(mid)) {
      ans = mid;
      // cout<<mid<<endl;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  printf("%d\n", ans);
}

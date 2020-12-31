#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int xi[N], yi[N];

ll cost_horz(int n, ll y) {
  ll cost = 0;
  for (int i = 0; i < n; ++i)
    cost += abs(yi[i] - y);
  return cost;
}

// median should be the answer (not sure for now)
ll solve_horz(int n) {

  ll beg = -2e9, end = 2e9 + 1, mid, ans = 1e18;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    ll c1 = cost_horz(n, mid);
    ll c2 = cost_horz(n, mid + 1);
    ans = min(ans, min(c1, c2));
    if (c1 < c2)
      end = mid - 1;
    else
      beg = mid + 1;
  }
  return ans;
}

ll cost_line(int n, ll x) {
  ll cost = 0;
  for (int i = 0; i < n; ++i)
    cost += abs(x - xi[i] + i);
  return cost;
}

// median should be the answer (not sure for now)
ll solve_line(int n) {

  ll beg = -2e9, end = 2e9, mid, ans = 1e18;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    ll c1 = cost_line(n, mid);
    ll c2 = cost_line(n, mid + 1);
    ans = min(ans, min(c1, c2));
    if (c1 < c2)
      end = mid - 1;
    else
      beg = mid + 1;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d", xi + i, yi + i);
    ll ycos = solve_horz(n);
    sort(xi, xi + n);
    ll xcos = solve_line(n);
    // cout << ycos << " " << xcos << endl;
    printf("Case #%d: %lld\n", q + 1, xcos + ycos);
  }
  return 0;
}

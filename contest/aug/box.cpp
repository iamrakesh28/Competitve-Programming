#include <iostream>

using namespace std;

typedef long long ll;
const int inf = 1e6 + 6e5;

ll sum1(ll n) {
  ll sum = n * (n + 1) / 2;
  ll temp = n * (n + 1) * (2 * n + 1) / 6;
  if (sum & 1) {
    sum = sum / 2 + temp / 2;
    sum++;
  }
  else {
    sum = sum / 2 + temp / 2;
  }
  return sum;
}

ll sum2(ll n) {
  ll sum = n * (n + 1) / 2;
  return sum;
}

ll bin1(ll n) {
  ll beg = 0, end = inf, mid, ans;
  while (beg <= end) {
    mid  = (beg + end) >> 1;
    ll sum = sum1(mid);
    if (sum <= n) {
      ans = mid;
      beg = mid + 1;
    }
    else
      end = mid - 1;
  }
  return ans;
}

ll bin2(ll n) {
  ll beg = 0, end = inf, mid, ans;
  while (beg <= end) {
    mid  = (beg + end) >> 1;
    ll sum = sum2(mid);
    if (sum >= n) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  //cout << sum1(inf) << endl;
  while (t--) {
    ll n;
    scanf("%lld", &n);
    ll n1 = bin1(n);
    ll sum = sum1(n1);
    //cout << sum << endl;
    if (sum == n) {
      cout << sum2(n1) << endl;
      continue;
    }
    sum = n - sum;
    ll n2 = bin2(sum);
    //cout << n1 << " " << n2 << endl;
    n1 = sum2(n1);
    cout << n1 + n2 << endl;
  }
  return 0;
}

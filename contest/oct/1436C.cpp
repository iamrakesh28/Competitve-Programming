#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1005, prime = 1e9 + 7;
ll fact[N];

ll inv(ll a, ll n) {
  ll r = 1;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n = n >> 1;
  }
  return r;
}

int main() {
  int n, x, pos, gt = 0, lt = 0;
  scanf("%d%d%d", &n, &x, &pos);

  int left = 0, right = n, mid;

  fact[0] = 1;
  for (int i = 1; i < N; ++i)
    fact[i] = (fact[i - 1] * i) % prime;
  
  while (left < right) {
    mid = (left + right) >> 1;
    if (mid > pos) {
      lt++;
      right = mid;
    }
    else if (mid < pos) {
      left = mid + 1;
      gt++;
    }
    else
      break;
  }
  cout << lt << " " << gt << endl;
  ll ans, one, two;
  ll temp = fact[gt] * fact[n - x - gt] % prime;
  one = fact[n - x] * inv(temp, prime - 2) % prime;
  one = one * fact[gt] % prime;

  temp = fact[lt] * fact[x - lt - 1] % prime;
  two = fact[x - 1] * inv(temp, prime - 2) % prime;
  two = two * fact[lt] % prime;

  ans = one * two % prime;
  ans = ans * fact[n - lt - gt - 1] % prime;
  cout << ans << endl;
  return 0;
}

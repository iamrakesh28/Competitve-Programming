#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

const int N = 1e3 + 5, prime = 1e9 + 7;
int arr[N];
ll dp[N];

long long power(long long a, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n >>= 1;
  }
  return r;
}

int main() {
  int l, m;
  scanf("%d%d", &m, &l);
  for (int i = 0; i < l; ++i)
    scanf("%d", arr + i);
  sort(arr, arr + l);
  long long ans = 1;
  vector <int> d;
  int prev = 0, cnt = 0;
  for (int i = 0; i < l; ++i) {
    int diff = arr[i] - prev - 1;
    if (diff)
      d.push_back(diff);
    prev = arr[i];
  }
  int diff = m - arr[l - 1];
  if (diff)
    d.push_back(diff);
  for (int i = 0; i <= n; ++i) {
  }
  printf("%lld\n", ans);
  return 0;
}

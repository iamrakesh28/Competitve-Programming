#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 5e5 + 5, prime = 1e9 + 7;
ll fact[N], inv[N];
vector <int> freq[N], unique;

ll inverse(ll a, int n) {
  ll r = 1;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n >>= 1;
  }
  return r;
}

void init(int n) {
  fact[0] = 1;
  for (int i = 1; i < n; ++i)
    fact[i] = fact[i - 1] * i % prime;
  for (int i = 0; i < n; ++i)
    inv[i] = inverse(fact[i], prime - 2);
  return;
}

void reset(void) {
  for (int i : unique)
    freq[i].clear();
  unique.clear();
  return;
}

int main() {
  init(N - 2);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      freq[].push_back(ai - 1);
    }
    reset();
  }
  return 0;
}

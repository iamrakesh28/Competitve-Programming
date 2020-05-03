#include <iostream>
#include <vector>
#include <cstring>

typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
vector <int> d1, d2;
char s[N];

void odd(int n) {
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
}

void even(int n) {
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }
}

int main() {
  int n;
  scanf("%s", s);
  n = strlen(s);
  d1.resize(n), d2.resize(n);
  odd(n);
  even(n);
  ll ans = (ll)n * (n + 1) / 2;
  for (int i = 0; i < n; ++i) {
    int cnt = d1[i];
    ans -= cnt;
    cnt = d2[i];
    ans -= cnt;
  }
  printf("%lld\n", ans + 1);
  return 0;
}

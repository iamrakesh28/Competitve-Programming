#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  ll ans = b - a + 1, diff = 0;
  ans = ans * (c - b + 1);
  ans = ans * (d - c + 1);
  for (int i = a; i <= b; ++i) {
    ll temp;
    int s = i + c, j = c;
    if (s > d) {
      int cnt = s - d;
      j = j - cnt;
      if (j < b)
	continue;
      s = i + j;
    }
    int df = s - c + 1;
    if (j - df < b) {
      df = min(df, j - b + 1);
      temp = df;
      temp = temp * (temp + 1);
      temp = temp / 2;
      diff += temp;
      continue;
    }
    temp = df;
    temp = temp * (temp + 1) / 2;
    j = j - df;
    df = j - b + 1;
    diff += temp;
    temp = df;
    temp = temp * (d - c + 1);
    diff += temp;
  }
  ans = ans - diff;
  printf("%lld\n", ans);
  return 0;
}

#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void divide(int &a, int &b, int n, int val, int mul) {
  while (n > 0 && (a % val == 0)) {
    a = a / val;
    a = a * mul;
    n--;
  }

  while (n > 0 && (b % val == 0)) {
    b = b / val;
    b = b * mul;
    n--;
  }
  return;
}

int main() {
  int a1, b1, a2, b2;
  ll prod[2];
  scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
  prod[0] = (ll)a1 * b1;
  prod[1] = (ll)a2 * b2;
  ll _gcd = gcd(prod[0], prod[1]);
  prod[0] = prod[0] / _gcd;
  prod[1] = prod[1] / _gcd;
  //cout << prod[0] << " " << prod[1] << endl;
  int cnt[2][2] = {{0, 0}, {0, 0}};
  for (int j = 0; j < 2; ++j) {
    for (int i = 2; i <= 3; ++i) {
      int execs = 0;
      while (prod[j] % i == 0) {
	execs++;
	prod[j] /= i;
      }
      cnt[j][i - 2] = execs;
    }
    if (prod[j] > 1) {
      puts("-1");
      return 0;
    }
  }
  int ans = 0;
  if (cnt[0][1]) {
    ans = cnt[0][1];
    ans = ans + abs(cnt[1][0] - cnt[0][0] - ans);
    divide(a1, b1, cnt[0][1], 3, 2);
    if (cnt[0][0])
      divide(a1, b1, cnt[0][0] + cnt[0][1], 2, 1);
    else {
      if (cnt[0][1] >= cnt[1][0])
	divide(a1, b1, cnt[0][1] - cnt[1][0], 2, 1);
      else
	divide(a2, b2, cnt[1][0] - cnt[0][1], 2, 1);
    }
  }
  else {
    ans = cnt[1][1];
    ans = ans + abs(cnt[0][0] - cnt[1][0] - ans);
    divide(a2, b2, cnt[1][1], 3, 2);
    if (cnt[1][0])
      divide(a2, b2, cnt[1][0] + cnt[1][1], 2, 1);
    else {
      if (cnt[1][1] >= cnt[0][0])
	divide(a2, b2, cnt[1][1] - cnt[0][0], 2, 1);
      else
	divide(a1, b1, cnt[0][0] - cnt[1][1], 2, 1);
    }
  }
  printf("%d\n%d %d\n%d %d\n", ans, a1, b1, a2, b2);
  return 0;
}

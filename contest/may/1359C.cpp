#include <iostream>

typedef long long ll;
using namespace std;

const ll inf = 1e12;

double ab(double v) {
  if (v >= 0)
    return v;
  return -1 * v;
}

ll find(double up, double t, double temp) {
  ll beg = 1, end = inf, ans = 3, mid;
  double diff = up;
  diff = diff / 3;
  diff = diff + temp;
  diff = ab(diff - t);
  while (beg <= end) {
    double d = up;
    mid = beg + end >> 1;
    d = d / (2 * mid + 1);
    d = d + temp;
    if (d == t) {
      ans = 2 * mid + 1;
      break;
    }
    else if (d > t) {
      double st = ab(d - t);
      if (diff > st) {
	ans = 2 * mid + 1;
	diff = st;
      }
      else if (diff == st)
	ans = min(ans, 2 * mid + 1);
      beg = mid + 1;
    }
    else {
      double st = ab(d - t);
      if (diff > st) {
	ans = 2 * mid + 1;
	diff = st;
      }
      else if (diff == st)
	ans = min(ans, 2 * mid + 1);
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int h, c, t;
    scanf("%d%d%d", &h, &c, &t);
    if (h <= t) {
      puts("1");
      continue;
    }
    if (h + c >= 2 * t) {
      puts("2");
      continue;
    }
    double temp = (double)(h + c) / 2.0;
    double up = (double)(h - c) / 2.0;
    ll ans = find(up, (double)t, temp);
    printf("%lld\n", ans);
  }
  return 0;
}

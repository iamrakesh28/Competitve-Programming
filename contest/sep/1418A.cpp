#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    ll sticks = (ll)k * (y + 1), temp;
    ll beg = 2, end = (ll)1e9 + 100, mid, ans = 2;
    while (beg <= end) {
      mid = (beg + end) >> 1;
      temp = mid * x + x;
      temp = temp + 1 - mid;
      temp = temp * mid;
      temp = temp / 2;
      
    }
  }
  return 0;
}

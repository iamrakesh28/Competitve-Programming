#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, side;
    scanf("%d", &n);
    side = n << 1;
    double angle = PI / side;
    double ta = sin(angle), co = cos(angle / 2.0);
    double ans = co / ta;
    printf("%0.10lf\n", ans);
  }
  return 0;
}

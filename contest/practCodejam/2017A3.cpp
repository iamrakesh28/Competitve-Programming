#include <iostream>
#include <cstring>

using namespace std;

const int inf = 1e9;
int win[4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int hd, ad, hk, ak, b, d, a, k;
    scanf("%d%d%d%d%d%d", &hd, &ad, &hk, &ak, &b, &d);
    // just attack
    a = hk / ad;
    if (hk % ad)
      a++;
    win[0] = a;
    if (hd <= (a - 1) * ak) {
      k = hd / ak + 1;
    }
  }
  return 0;
}

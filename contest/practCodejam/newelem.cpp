#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int N = 3e3;
pair <int, int> cj[N];
set <pair <int, int>> order;

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d", &cj[i].first, &cj[i].second);
    order.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
	int k = cj[j].second - cj[i].second;
	int den = cj[i].first - cj[j].first;
	if (den == 0)
	  continue;
	if (k > 0 && den > 0 || k < 0 && den < 0) {
	  if (k < 0)
	    k = -k, den = -den;
	  int gcd = __gcd(k, den);
	  order.insert({k / gcd, den / gcd});
	}
      }
    }
    printf("Case #%d: %d\n", q + 1, order.size() + 1);
  }
  return 0;
}

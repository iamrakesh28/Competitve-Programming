#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int inf = 1e9 + 7;

int main() {

  int n1, n2, n3;
  scanf("%d%d%d", &n1, &n2, &n3);

  LL sum = 0;
  int a[] = {inf, inf, inf};

  for (int i = 0; i < n1; ++i) {
    int ai;
    scanf("%d", &ai);
    sum += ai;
    a[0] = min(a[0], ai);
  }

  for (int i = 0; i < n2; ++i) {
    int ai;
    scanf("%d", &ai);
    sum += ai;
    a[1] = min(a[1], ai);
  }

  for (int i = 0; i < n3; ++i) {
    int ai;
    scanf("%d", &ai);
    sum += ai;
    a[2] = min(a[2], ai);
  }

  sort(a, a + 3);

  // cout << a[0] << " " << a[1] << endl;
  printf("%lld\n", sum - 2 * a[0] - 2 * a[1]);
  return 0;
}

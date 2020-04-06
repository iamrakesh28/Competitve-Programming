#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
  }
  return 0;
}

#include <iostream>

using namespace std;

int main() {

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = n >> 1;
    if (n & 1)
      ans++;
    printf("%d\n", ans);
  }
  return 0;
}

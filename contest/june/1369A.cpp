#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n % 4 == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

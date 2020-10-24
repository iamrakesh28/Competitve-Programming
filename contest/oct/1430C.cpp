#include <iostream>

using namespace std;


int main() {
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    puts("2");
    printf("%d %d\n", n - 1, n);
    int a = n - 2, b = n;
    for (int i = 0; i < n - 2; ++i) {
      printf("%d %d\n", a, b);
      a--, b--;
    }
  }
  return 0;
}

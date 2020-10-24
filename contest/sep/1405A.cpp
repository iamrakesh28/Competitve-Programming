#include <iostream>

using namespace std;

int p[105];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", p + i);
    for (int i = 0; i < n / 2; ++i) {
      int temp = p[i];
      p[i] = p[n - i - 1];
      p[n - i - 1] = temp;
    }
      
    for (int i = 0; i < n; ++i)
      printf("%d ", p[i]);
    puts("");
  }
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int N = 105;
int a[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, ans;
    bool found = false;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      if (a[i] % 2 == 0 && found == false) {
	ans = i + 1;
	found = true;
      }
    }
    if (found) {
      puts("1");
      printf("%d\n", ans);
      continue;
    }
    if (n <= 1) {
      puts("-1");
      continue;
    }
    puts("2");
    printf("%d %d\n", 1, 2);
  }
  return 0;
}

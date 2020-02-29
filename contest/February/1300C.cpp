#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n, ind = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for (int j = 30; j >= 0; j--) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if ((1 << j) & a[i]) {
	cnt++;
	ind = i;
      }
    if (cnt == 1)
      break;
  }
  printf("%d ", a[ind]);
  for (int i = 0; i < n; ++i)
    if (i != ind)
      printf("%d ", a[i]);
  puts("");
  return 0;
}

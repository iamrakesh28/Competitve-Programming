#include <iostream>

using namespace std;

const int N = 3e5 + 5;
int a[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, mid, pos = 1;
    scanf("%d", &n);
    mid = n / 2;
    if (n % 2 == 0)
      mid--;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      if (i <= mid) {
	if (a[i] < i)
	  pos = -1;
      }
      else {
	if (a[i] < n - 1 - i)
	  pos = -1;
      }
    }
    if (n % 2 == 0) {
      if (a[mid] <= mid) {
	if (a[mid + 1] <= mid)
	  pos = -1;
      }	
    }
    if (pos == 1) {
      puts("Yes");
      continue;
    }
    puts("No");
  }
}

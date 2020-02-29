#include <iostream>

using namespace std;

int arr[105];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, ans = 0;
    scanf("%d", &n);
    int sum = 0, prod = 1, cnt = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
      sum += arr[i];
      if (arr[i] == 0)
	prod = 0, cnt++;
    }
  
    if (prod == 0) {
      if (sum >= 0)
	ans += cnt;
      else {
	sum += cnt;
	ans += cnt;
	if (sum == 0)
	  ans++;
      }
    }
    else {
      if (sum == 0)
	ans = 1;
    }
    printf("%d\n", ans);
  }
}

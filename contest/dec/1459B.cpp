#include <iostream>

using namespace std;

int main() {

  int n, steps = 1, ans = 0;
  scanf("%d", &n);

  for (int i = 0; i < n ; ++i)
    for (int j = 0; j < n; ++j) {
      int odd = i + j;
      if ((odd & 1) && (n & 1))
        ans++;
      else if (odd % 2 == 0 && n % 2 == 0)
        ans++;
    }

  int temp = 0;
  for (int i = 0; i < n; ++i) {
    int odd = i;
    if ((odd & 1) && (n & 1))
      temp++;
    else if (odd % 2 == 0 && n % 2 == 0)
      temp++;
  }
  temp = temp << 1;
  ans = (ans << 2) - temp;
  
  printf("%d\n", ans);
  return 0;
}

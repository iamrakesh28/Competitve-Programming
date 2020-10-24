#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int ai[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", ai + i);
  sort(ai, ai + n);
  int val = n / 2;
  if ((n & 1) == 0)
    val--;
  int ind = 0;
  for (int i = n - 1; i >= 0; i--, ind += 2) {
    if (ind >= n)
      break;
    ans[ind] = ai[i];
  }
  ind = 1;
  for (int i = 0; i < n; i++, ind += 2) {
    if (ind >= n)
      break;
    ans[ind] = ai[i];
  }
  
  printf("%d\n", val);
  for (int i = 0; i < n; ++i)
    printf("%d ", ans[i]);
  puts("");
  return 0;
}

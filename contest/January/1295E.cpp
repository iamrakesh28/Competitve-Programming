#include <iostream>

using namespace std;

const int N = 1e5;
bool pres[N];
int p[N], a[N], ran[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
    ran[p[i] - 1] = i;
    pres[i] = false;
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  long long ans = 1e18, left = 0, right = 0;
  for (int i = 0; i < n; ++i) {
    if (pres[i]) {
      left -= a[ran[i]];
      if (p[i] - 1 <= i) {
	pres[p[i] - 1] = true;
	right -= a[i];
      }
      else {
	pres[p[i] - 1] = true;
	left += a[i];
      }
    }
    else {
      right += a[ran[i]];
      if (p[i] - 1 <= i) {
	pres[p[i] - 1] = true;
	right -= a[i];
      }
      else {
	pres[p[i] - 1] = true;
	left += a[i];
      }
    }
    cout<<(left+right)<<endl;
    ans = min(ans, left + right);
  }
  printf("%lld\n", ans);
  return 0;
}

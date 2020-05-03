#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int pref[N], a[N], peak[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, ans = 0, l = 0;
    scanf("%d%d", &n, &k);
    pref[0] = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    pref[1]  = 0;
    peak[0] = 0;
    for (int i = 1; i < n - 1; ++i) {
      pref[i + 1] = pref[i];
      peak[i] = 0;
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
	pref[i + 1]++;
	peak[i] = 1;
      }
    }
    pref[n] = pref[n - 1];
    peak[n - 1] = 0;
    for (int i = 0; i + k <= n; ++i) {
      int sum = pref[i + k] - pref[i];
      //cout<<sum<<endl;
      if (peak[i + k - 1])
	sum--;
      if (peak[i])
	sum--;
      if (sum + 1 > ans) {
	ans = sum + 1;
	l = i;
      }
    }
    printf("%d %d\n", ans, l + 1);
  }
  return 0;
}

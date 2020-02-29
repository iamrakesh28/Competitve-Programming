#include <iostream>

using namespace std;

const int N = 4e3;
int ai[N];

int solve(int i, int j, int m, int n) {
  int ans = 2e9;
  int l, r;
  l = m + i - 1, r = j + 1; 
  while (l >= i - 1) {
    int left = ai[l + 1];
    int right = ai[r - 1];
    l--;
    r--;
    ans = min(ans, max(left, right));
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, m, k, x = -1;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", ai + i);
    int l, r;
    k = min(k, m - 1);
    l = k - 1, r = n;
    while (l >= -1) {
      int rem = m - 1 - k;
      if (rem <= 0) {
	x = max(x, max(ai[l + 1], ai[r - 1]));
      }
      else {
	x = max(x, solve(l + 1, r - 1, rem, n));
      }
      l--;
      r--;
      //cout<<l<<endl;
    }
    printf("%d\n", x);
  }
  return 0;
}

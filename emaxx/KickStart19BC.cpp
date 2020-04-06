#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5;
int A[N], alph[N];

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int j = 0; j < n; ++j)
      scanf("%d", A + j);
    memset(alph, 0, sizeof alph);
    int ans = 1, l = 0, r = 0;
    while (r + 1 < n) {
      while (r + 1 < n) {
	if (alph[A[r + 1] - 1] + 1 <= s)
	  alph[A[r + 1] - 1]++;
	else
	  break;
	r++;
      }
      //cout<<l<<" "<<r<<endl;
      ans = max(ans, r - l + 1);
      alph[A[l] - 1]--;
      l++;
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}

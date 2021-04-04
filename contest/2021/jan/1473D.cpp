#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char ins[N];
pair <int, int> L[N], R[N];
int curr[N];

void process(int n) {

  int mn = 0, mx = 0, cnt = 0;
  L[0] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    if (ins[i - 1] == '+')
      cnt ++;
    else
      cnt --;
    curr[i] = cnt;
    mx = max(mx, cnt);
    mn = min(mn, cnt);
    L[i] = {mx, mn};
  }
  
  R[n + 1] = {0, 0};
  mx = mn = cnt = 0;
  int prev = -1;
  for (int i = n; i > 0; --i) {
    if (ins[i - 1] == '+') {
      mx ++, mn ++;
      cnt ++;
      if (i == n)
        prev = 1;
      else if (prev == 0) {
        cnt = 1;
        prev = 1;
      }
    }
    else {
      cnt --;
      mx --;
      mn --;
      if (i == n)
        prev = 0;
      else if (prev == 1) {
        prev = 0;
        cnt = -1;
      }
    }

    mx = max(mx, cnt);
    mn = min(mn, cnt);
    R[i] = {mx, mn};
  }
  
  return ;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", ins);

    process(n);
    while (m--) {
      int l, r;
      scanf("%d%d", &l, &r);

      int mx = L[l - 1].first, mn = L[l - 1].second, cnt = curr[l - 1];
      int rmax = R[r + 1].first, rmin = R[r + 1].second;

      mx = max(mx, cnt + rmax);
      mn = min(mn, cnt + rmin);
      int ans = mx - mn + 1;
      printf("%d\n", ans);
    }
  }
  
  return 0;
}

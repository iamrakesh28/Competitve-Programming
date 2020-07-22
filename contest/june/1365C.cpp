#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int inva[N], invb[N];
int ans[N << 1];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    inva[a - 1] = i;
  }
  for (int i = 0; i < n; ++i) {
    int b;
    scanf("%d", &b);
    invb[b - 1] = i;
  }
  for (int i = 0; i < n; ++i) {
    int diff = inva[i] - invb[i];
    if (diff < 0) {
      diff = -diff;
      ans[diff]++;
    }
    else
      ans[n - diff]++;
    //cout<<diff<<endl;
  }
  int mx = 0;
  for (int i = 0; i <= N; ++i)
    mx = max(mx, ans[i]);
  printf("%d\n", mx);
  return 0;
}

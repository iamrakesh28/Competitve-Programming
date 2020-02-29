#include <iostream>

using namespace std;

const int N = 1e5 + 5;

void solve(int n, long long ans) {
  if (ans)
    printf("%d", 7);
  for (int i = 0; i < n; ++i)
    printf("%d", 1);
  puts("");
  return ;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    long long ans = 0;
    scanf("%d", &n);
    if (n & 1) {
      n = n / 2 - 1;
      ans = 7;
      solve(n, ans);
    }
    else {
      solve(n / 2, 0);
    }
    //cout<<ans<<endl;
  }
  return 0;
}

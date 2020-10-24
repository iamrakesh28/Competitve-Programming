#include <iostream>

using namespace std;

const int N = 100;
char S[N << 1], ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%s", &n, S);
    for (int i = 0; i < n; ++i) {
      int ind = 2 * i;
      ans[i] = S[ind];
    }
    ans[n] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}

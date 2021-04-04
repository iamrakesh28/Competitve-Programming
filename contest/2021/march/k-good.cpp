#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char S[N];

int main() {

  int t;
  scanf("%d", &t);

  for (int h = 0; h < t; ++h) {
    int n, k;
    scanf("%d%d%s", &n, &k, S);

    int good = 0;
    for (int i = 0; i < (n >> 1); ++i) {
      if (S[i] != S[n - i - 1])
        good++;
    }

    printf("Case #%d: %d\n", h + 1, abs(k - good));
  }
  
  return 0;
}

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;
int p[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    /*
    LL invA = 0;
    for (int i = 0; i < n - k; ++i) {
      invA += (i + 1);
      if (i != n - k - 1)
        invA += (i + 1);
    }

    LL invR;
    invR = invA;
    */
    int len = 2 * k - n - 1;
    for (int i = 0; i < len; ++i) {
      p[i] = i + 1;
    }

    int val = k;
    for (int i = len; i < k; ++i)
      p[i] = val --;

    for (int i = 0; i < k; ++i)
      printf("%d ", p[i]);
    puts("");
  }
  
  return 0;
}

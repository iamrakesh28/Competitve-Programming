#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
int a[N], b[N];
LL damage[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int A, B, n;
    scanf("%d%d%d", &A, &B, &n);

    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);

    for (int i = 0; i < n; ++i)
      scanf("%d", b + i);

    LL sum = 0;
    for (int i = 0; i < n; ++i) {
      int att;
      if (b[i] % A == 0)
        att = b[i] / A;
      else
        att = b[i] / A + 1;
      damage[i] = (LL)att * a[i];
      sum += damage[i];
    }

    bool poss = false;
    for (int i = 0; i < n; ++i) {
      LL temp = sum - damage[i];
      if (temp >= B)
        continue;
      
      int att;
      if (b[i] % A == 0)
        att = b[i] / A;
      else
        att = b[i] / A + 1;

      
      LL dam = (LL)(att - 1) * a[i];
      if (dam + temp < B) {
        poss = true;
        break;
      }
    }

    if (poss)
      puts("YES");
    else
      puts("NO");
  }
  
  return 0;
}

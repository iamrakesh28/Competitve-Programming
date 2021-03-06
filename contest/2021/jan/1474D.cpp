#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int a[N];
long long p[N], s[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      if (i == 0) {
        p[i]= a[i];
      }
      else
        p[i] = a[i] - p[i - 1];
    }
    s[n - 1] = a[n - 1];
    int index = 0;
    
    for (int i = n - 2; i >= 0; i--) {
      s[i] = a[i] - s[i + 1];
      if (s[i] < 0) {
        index = max(i, index);
      }
    }

    bool poss = false;

    for (int i = 0; i < n - 1; ++i) {

      if (i < index - 1)
        continue;

      int diff = a[i + 1] - a[i];
      long long l = diff + p[i], r = s[i + 1] - diff;

      if (l == r && l >= 0) {
        poss = true;
        break;
      }
      
      if (p[i] < 0)
        break;

      if (p[i] == s[i + 1]) {
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

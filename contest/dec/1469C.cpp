#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;
int h[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i)
      scanf("%d", h + i);

    LL l, r;
    l = r = h[0];

    bool poss = true;
    
    for (int i = 1; i < n - 1; ++i) {
      LL curl, curr;
      curl = h[i];
      curr = h[i] + k - 1;

      if (curr + k < l + 1) {
        poss = false;
        break;
      }

      if (r + k < h[i] + 1) {
        poss = false;
        break;
      }

      if (l <= curl)
        l = curl;
      else
        l = max(l - (k - 1), curl);

      if (r >= curr)
        r = curr;
      else
        r = min(r + k - 1, curr);
        
    }

    if (h[n - 1] + k < l + 1)
      poss = false;
    
    if (r + k < h[n - 1] + 1)
      poss = false;
    
    if (poss)
      puts("YES");
    else
      puts("NO");
  }
  
  return 0;
}

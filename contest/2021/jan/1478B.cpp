#include <iostream>

using namespace std;

const int N = 1e4 + 5;
bool poss[100];

bool check(int num, int d) {

  bool found = false;
  
  while (num) {
    int digit = num % 10;
    if (digit == d) {
      found = true;
      break;
    }
    num = num / 10;
  }
  
  return found;
}

bool brute(int n, int d) {

  if (n < d)
    return false;
  if (check(n, d))
    return true;

  for (int i = d; i < n; ++i) {
    if (check(i, d)) {
      if (brute(n - i, d))
        return true;
    }
  }

  return false;
}


int main() {

  int t;
  scanf("%d", &t);
  while (t--) {
    int q, d;
    scanf("%d%d", &q, &d);

    if (d > 1) {
      for (int i = 1; i < 10 * d; ++i) {
        poss[i] = brute(i, d);
      }
    }
    
    for (int i = 0; i < q; ++i) {
      int ai;
      scanf("%d", &ai);

      if (ai % d == 0) {
        puts("YES");
        continue;
      }
      if (10 * d <= ai) {
        puts("YES");
        continue;
      }

      if (poss[ai])
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}

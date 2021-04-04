#include <iostream>

using namespace std;

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    if (n & 1) {
      k--;
      int rounds = k / n;
      int pos = 1 + rounds * 2;
      pos = (pos - 1)% n;
      pos = pos + 1;
      if (pos == n)
        pos = 1;

      
      int rem = k % n, exp;
      if (k % n == 0 && k > 0)
        rem++;

      // cout << rounds << " " << pos << endl;

      int middle = (n - pos) / 2;
      if (rem < middle) {
        exp = pos + rem;
      }
      else {
        pos = pos + middle + 1;
        rem -= middle;

        if (rem <= n - pos)
          exp = pos + rem;
        else {
          rem -= (n - pos + 1);
          int posb = n - (middle + n - pos + 1);
          pos = 1;

          int diff = posb - pos;
          if (diff & 1) {
            exp = pos + rem;
          }
          else {
            int coll = diff / 2;
            if (rem >= coll)
              exp = pos + rem + 1;
            else
              exp = pos + rem;
          }
          
        }
      }
      printf("%d\n", exp);
    }
    else {
      k--;
      int pos = k % n;
      printf("%d\n", pos + 1);
    }
  }
  
  return 0;
}

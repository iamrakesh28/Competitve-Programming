#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int shots = a + b + c;
    bool poss = true;

    if (shots % 9)
      poss = false;
    else {
      int enhn = shots / 9;
      if (min(a, min(b, c)) < enhn)
        poss = false;
    }
    
    if (poss)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

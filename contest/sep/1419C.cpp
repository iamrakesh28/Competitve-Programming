#include <iostream>

using namespace std;

const int N = 1e3 + 5;
int ai[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    bool poss = true;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
      scanf("%d", ai + i);
      if (ai[i] != x)
	poss = false;
    }
    if (poss) {
      puts("0");
      continue;
    }
    int delta = 0;
    poss = false;
    for (int i = 0; i < n; ++i) {
      int diff = x - ai[i];
      delta = delta + diff;
      if (ai[i] == x)
	poss = true;
    }
    if (delta == 0 || poss)
      puts("1");
    else
      puts("2");
  }
  return 0;
}

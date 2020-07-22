#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, turn = 0, found = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      if (found == -1) {
	if (ai > 1) {
	  turn = i;
	  found = 1;
	}
      }
    }
    if (found == -1) {
      if (n & 1)
	puts("First");
      else
	puts("Second");
    }
    else {
      if (turn & 1)
	puts("Second");
      else
	puts("First");
    }
  }
  return 0;
}

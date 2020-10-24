#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    bool even = false, odd = false;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      char ch;
      scanf(" %c", &ch);
      int num = ch - '0';
      if (i & 1) {
	if ((num & 1) == 0)
	  even = true;
      }
      else {
	if (num & 1)
	  odd = true;
      }
    }
    if (n & 1) {
      if (odd)
	puts("1");
      else
	puts("2");
    }
    else {
      if (even)
	puts("2");
      else
	puts("1");
    }
  }
  return 0;
}

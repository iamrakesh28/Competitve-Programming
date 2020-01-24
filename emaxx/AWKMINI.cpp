#include <iostream>

using namespace std;

const int N = 1e5 + 5;
char s[N];

int main() {
  int q, b, g, i, small, large;
  scanf("%d", &q);
  char ch = getchar();
  while (q--) {
    b = g = i = 0;
    while ((ch = getchar()) != '\n') {
      if (ch == 'b')
	b++;
      else
	g++;
      s[i++] = '0';
    }
    small = min(b, g);
    large = max(b, g);
    for (int j; j <; ++j)
      s[j] = '1';
    if (large & 1)
      
  }
  return 0;
}

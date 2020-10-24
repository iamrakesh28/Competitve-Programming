#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A')
	a++;
      else {
	if (a)
	  a--;
	else
	  b = (b + 1) % 2;
      }
    }
    printf("%d\n", a + b);
  }
  return 0;
}

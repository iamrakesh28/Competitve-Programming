#include <iostream>
#include <cstring>

using namespace std;

char s[1000000];

int main() {
  int r, ans, rem;
  scanf("%s", s);
  r = strlen(s);
  if (r >= 2)
    ans = (s[r - 2] - '0') * 10 + (s[r - 1] - '0');
  else
    ans = s[r - 1] - '0';
  rem = ans % 4;
  if (rem == 0)
    puts(s);
  else if (rem == 1)
    puts("1");
  else if (rem == 2) {
    s[r - 1] = s[r - 1] + 1;
    puts(s);
  }
  else
    puts("0");
  return 0;
}

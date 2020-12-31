#include <iostream>
#include <cstring>

using namespace std;

char s[105];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%s", s);
    int n = strlen(s);

    if (n & 1) {
      puts("NO");
      continue;
    }

    if (s[0] == ')' || s[n - 1] == '(') {
      puts("NO");
      continue;
    }

    puts("YES");
  }
  
  return 0;
}

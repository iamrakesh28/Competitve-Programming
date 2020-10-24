#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 5;
char s[N];

int main() {
  int n, cnt;
  scanf("%s", s);
  n = strlen(s);
  cnt = 6;
  printf("%d\n", cnt);
  // ab
  puts("L 2");
  // bab
  puts("L 2");
  // abab
  puts("L 2");
  // babab
  puts("L 2");
  // ababab
  puts("R 3");
  // baba
  n += 4;
  n = n + n - 3;
  printf("R %d\n", n - 2);
  return 0;
}

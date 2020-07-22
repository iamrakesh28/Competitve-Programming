#include <iostream>
#include <cstring>

using namespace std;

char s[1000005];
int main () {
  int n;
  scanf("%d%s", &n, s);
  printf("%d %d\n", n, strlen(s));
  return 0;
}

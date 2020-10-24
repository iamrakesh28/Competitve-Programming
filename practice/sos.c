#include <stdio.h>

int main() {
  long long b = ~(1 << 1);
  long long a = b & 0x00fffffffffff000;
  printf("%p %p\n", b, a);
  return 0;
}

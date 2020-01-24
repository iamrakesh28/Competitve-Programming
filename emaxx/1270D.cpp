#include <iostream>

using namespace std;

int main() {
  int n, k, small = 0, pos, val, last, poss = 0;
  scanf("%d%d", &n, &k);
  last = k + 1;
  putchar('?');
  for (int i = 0; i < k; ++i)
    printf(" %d", i + 1);
  puts("");
  fflush(stdout);
  scanf("%d%d", &pos, &val);

  putchar('?');
  for (int i = 0; i < k; ++i)
    if (i != pos - 1)
      printf(" %d", i + 1);
  printf(" %d\n", last);
  fflush(stdout);
  int p, v;
  scanf("%d%d", &p, &v);
  if (v < val)
    poss = 1;

  for (int i = 0; i < k; ++i) {
    if (i == pos - 1)
      continue;
    putchar('?');
    for (int j = 0; j < k; ++j)
      if (j != i)
	printf(" %d", j + 1);
    printf(" %d\n", last);
    fflush(stdout);
    scanf("%d%d", &p, &v);
    if (poss) {
      if (v == val)
	small++;
    }
    else
      if (v > val)
	small++;
	
  }
  printf("! %d\n", small + 1);
  fflush(stdout);
  return 0;
}

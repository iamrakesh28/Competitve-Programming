#include <iostream>
#include <cmath>

using namespace std;

const int N = 50000;
char arr[2 * N];

bool solve(int i, int sum, char *c, int n) {
  if (i == 0) {
    int num = sqrt(sum);
    if (num * num == sum) {
      printf("%d ", sum);
      for (int j = 0; j < n; j++)
	if (c[j] == '1')
	  break;
	else
	  putchar(c[j]);
      return true;
    }
    return false;
  }
  for (int j = 1; j < 10; ++j) {
    c[i] = '0' + j;
    if (solve(i - 1, sum + j * j, c, n) == false)
      continue;
    return true;
  }
  return false;
}

int main() {

  for (int i = 1; i <= N; ++i) {
    printf("%d ", i);
    bool val = solve(i, 0, arr, i);
    puts("");
  }
  return 0;
}

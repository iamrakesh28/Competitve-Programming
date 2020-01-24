#include <iostream>
#include <cstring>

using namespace std;

const int size = 2e5 + 5;
bool x[size];
int dpMin[size][4], dpMax[size][4];

int solve(int xi, int state) {
  if (xi == 0)
    return 0;
  if (dpMin[xi][state] == -1) {
    if (x[xi - 1] == true) {
      switch (state) {
      case 0 : dpMin[xi][state] = min(solve(xi - 1, 1), min(solve(xi - 1, 0), solve(xi - 1, 2))) + 1;
	break;
      case 1 : dpMin[xi][state] = min(solve(xi - 1, 1) + 1, min(solve(xi - 1, 0), solve(xi - 1, 2) + 1));
	break;
      case 2 : dpMin[xi][state] = min(solve(xi - 1, 1), min(solve(xi - 1, 1) + 1, solve(xi - 1, 3) + 1));
	break;
      case 3 : dpMin[xi][state] = min(solve(xi - 1, 1), min(solve(xi - 1, 1), solve(xi - 1, 3) + 1));
	break;
      }
    }
    else
      dpMin[xi][state] = solve(xi - 1, state >> 1);
  }
  return dpMin[xi][state];
}

int main() {
  int n;
  scanf("%d", &n);
  memset(x, false, sizeof(bool) * n);
  for (int i = 0; i < n; ++i) {
    int xi;
    scanf("%d", &xi);
    x[xi - 1] = true;
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < 4; ++j)
      dpMin[i][j] = -1;
  int Min = solve(n, 0);
  printf("%d \n", Min);
  return 0;
}

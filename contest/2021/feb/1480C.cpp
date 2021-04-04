#include <iostream>

using namespace std;

const int INF = 1e9;

void query(int i) {

  printf("? %d\n", i);
  fflush(stdout);

  return;
}

int solve(int n) {

  if (n == 1)
    return 1;
  
  int last;
  query(n);
  scanf("%d", &last);

  int beg = 1, end = n, mid, ind = 1;
  while (beg <= end) {

    int a1 = INF, a2, a3 = INF;
    mid = (beg + end) >> 1;
    query(mid);
    scanf("%d", &a2);

    if (mid > 1) {
      query(mid - 1);
      scanf("%d", &a1);
    }

    if (mid < n) {
      query(mid + 1);
      scanf("%d", &a3);
    }

    if (a2 < a1 && a2 < a3) {
      ind = mid;
      break;
    }

    int diff = n - mid;
    int exp = last - diff;

    if (exp < a2) {
      beg = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }

  return ind;
}

int main() {

  int n;
  scanf("%d", &n);
  printf("! %d\n", solve(n));
  fflush(stdout);
  
  return 0;
}


#include <iostream>

using namespace std;

int w[100], p[100];

int bin(int i, int prevW, int pi) {
  int beg = prevW + 1, end = prevW + 100, mid, ans, t;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    printf("1 %d %d\n", i + 1, mid);
    fflush(stdout);
    scanf("%d", &t);
    if (t == pi) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  ans = ans - prevW;
  return ans;
}

int main() {
  int n, prevW = 0, prevP = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int tw = prevW + 100, pi;
    printf("1 %d %d\n", i + 1, tw);
    fflush(stdout);
    scanf("%d", &pi);
    p[i] = pi - prevP;
    prevP = pi;
    w[i] = bin(i, prevW, pi);
    prevW += w[i];
  }
  puts("2");
  for (int i = 0; i < n; ++i)
    printf("%d ", w[i]);
  puts("");
  for (int i = 0; i < n; ++i)
    printf("%d ", p[i]);
  puts("");
  fflush(stdout);
  return 0;
}

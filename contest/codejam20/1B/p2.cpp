#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e9;
bool found;
char S[10];

bool query(int mid, int up) {
  bool ret = false;
  if (up)
    printf("%d %d\n", 0, mid);
  else
    printf("%d %d\n", mid, 0);
  fflush(stdout);
  scanf("%s", S);
  if (strcmp(S, "HIT") == 0)
    return true;
  if (strcmp(S, "MISS") == 0)
    return false;
  found = true;
  return true;
}

int left(int x, int up) {
  int beg = -N, end = N, mid, ans = -1;
  while (beg <= end) {
    mid = (beg + end) / 2;
    bool ret = query(mid, up);
    if (found)
      break;
    if (ret) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg
  }
}

int main() {
  int t;
  scanf("%d", &t);
  return 0;
}

#include <iostream>

using namespace std;

const int MAX_LINE = 100, MAX_LEN = 10000;
char ans[MAX_LINE][MAX_LEN + 1];

int solve() {
  
  int cheat, correct = -1;

  for (int i = 0; i < MAX_LINE; ++i) {
    int cnt = 0;
    for (int j = 0; j < MAX_LEN; ++j)
      cnt += (ans[i][j] - '0');

    if (correct < cnt) {
      correct = cnt;
      cheat = i + 1;
    }
  }

  return cheat;
}

int main() {

  int t, p;
  scanf("%d%d", &t, &p);

  for (int q = 0; q < t; ++q) {

    for (int i = 0; i < MAX_LINE; ++i) {
      scanf("%s", ans + i);
    }

    printf("Case #%d: %d\n", q + 1, solve());
  }
  
  return 0;
}

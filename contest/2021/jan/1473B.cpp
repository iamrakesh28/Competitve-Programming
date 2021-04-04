#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;
char s[N], t[N];
int cycle[N];

int solve(char a[], char b[], int S, int T) {

  memset(cycle, 0, sizeof(int) * (T + 1));
  int ans = 0;

  int i = 0;
  while (true) {
    if (cycle[i] == 1)
      break;
    bool exist = true;
    for (int j = 0; j < S; ++j)
      if (a[j] != b[(i + j) % T]) {
        exist = false;
        break;
      }
    if (exist == false) {
      ans = -1;
      break;
    }
    cycle[i] = 1;
    i = (i + S) % T;
    ans ++;
  }

  return ans;
}

int main() {

  int q;
  scanf("%d", &q);

  while (q--) {
    scanf("%s%s", s, t);

    int S = strlen(s), T = strlen(t);
    if (S < T) {
      int result = solve(s, t, S, T);
      if (result < 0)
        printf("-1");
      for (int i = 0; i < result; ++i)
        printf("%s", s);
      puts("");
    }
    else {
      int result = solve(t, s, T, S);
      if (result < 0)
        printf("-1");
      for (int i = 0; i < result; ++i)
        printf("%s", t);
      puts("");
    }
  }
  
  return 0;
}

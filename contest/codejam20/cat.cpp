#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e3 + 5, inf = 1e9;
pair <int, int> coor[N];
char S[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int x, y;
    scanf("%d%d%s", &x, &y, S);
    int m = strlen(S);
    coor[0] = {x, y};
    for (int i = 0; i < m; ++i) {
      if (S[i] == 'S')
	y--;
      else if (S[i] == 'N')
	y++;
      else if (S[i] == 'E')
	x++;
      else
	x--;
      coor[i + 1] = {x, y};
    }
    int ans = inf;
    for (int i = 0; i <= m; ++i) {
      int a, b, tim;
      a = coor[i].first, b = coor[i].second;
      tim = abs(a) + abs(b);
      if (tim <= i)
	ans = min(ans, i);
    }
    printf("Case #%d: ", j + 1);
    if (ans == inf) {
      puts("IMPOSSIBLE");
      continue;
    }
    printf("%d\n", ans);
  }
  return 0;
}

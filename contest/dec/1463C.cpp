#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  vector <int> tm, x;
  
  while (t--) {
    int n;
    scanf("%d", &n);

    tm.resize(n);
    x.resize(n);

    for (int i = 0; i < n; ++i) {
      int ti, xi;
      scanf("%d%d", &ti, &xi);
      tm[i] = ti;
      x[i] = xi;
    }

    int cnt = 0, tarpos = 0, curpos = 0, dir;
    long long time = 0;

    for (int i = 0; i < n; ++i) {

      // give successful command
      if (time <= tm[i]) {
        curpos = tarpos;
        tarpos = x[i];
        time = (long long)tm[i] + abs(x[i] - curpos);

        if (x[i] >= curpos)
          dir = 1;
        else
          dir = -1;
        
        if (i == n - 1)
          cnt++;
        else if (time <= tm[i + 1]) {
          curpos = tarpos;
          cnt++;
        }
        else
          curpos += dir * (tm[i + 1] - tm[i]);
      }
      else {
        int newpos;

        if (i == n - 1 || tm[i + 1] >= time)
          newpos = tarpos;
        else
          newpos = curpos + dir * (tm[i + 1] - tm[i]);

        if (min(newpos, curpos) <= x[i] && x[i] <= max(newpos, curpos))
          cnt++;
        
        curpos = newpos;
      }
    }

    printf("%d\n", cnt);
  }
  
  return 0;
}

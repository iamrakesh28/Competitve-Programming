#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int a[N], b[N], c[N],
  ans[N], avail[N];
vector <int> req[N];

void reset(int n) {

  for (int i = 0; i < n; ++i) {
    req[i].clear();
    avail[i] = 0;
  }
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {

    int n, m;
    scanf("%d%d", &n, &m);

    reset(n);
    
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    for (int i = 0; i < n; ++i) {
      int bi;
      scanf("%d", &bi);
      b[i] = bi;
      if (a[i] != bi)
        req[bi - 1].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
      int ci;
      scanf("%d", &ci);
      avail[ci - 1]++;
      c[i] = ci;
    }

    bool poss = true;
    for (int i = 0; i < n; ++i) {
      if (req[i].size() > avail[i]) {
        poss = false;
        break;
      }
    }

    if (poss == false) {
      puts("NO");
      continue;
    }

    bool found = false;
    int last;
    for (int i = 0; i < n; ++i) {
      if (c[m - 1] == b[i]) {
        found = true;
        last = i;
        break;
      }
    }

    if (found == false) {
      puts("NO");
      continue;
    }

    for (int i = m - 1; i >= 0; --i) {
      int id = c[i] - 1;
      if (req[id].size()) {
        ans[i] = req[id][req[id].size() - 1];
        if (i == m - 1)
          last = ans[i];
        req[id].pop_back();
      }
      else {
        ans[i] = last;
      }
    }
    
    puts("YES");
    for (int i = 0; i < m; ++i)
      printf("%d ", ans[i] + 1);
    puts("");
  }
  
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, As = 0, B = 0;
  scanf("%d", &n);

  vector <pair <int, int>> glass(n);
  for (int i = 0; i < n; ++i) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    glass[i] = {ai, bi};
    As += ai;
    B += bi;
  }
  
  vector < vector <int>> prev(n + 1, vector <int> (As + 1)),
    cur(n + 1, vector <int> (As + 1));
  
  for (int i = 0; i <= n; ++i) {
    for (int k = 0; k <= n; ++k)
      for (int cap = 0; cap <= As; ++cap) {
        if (i == 0) {
          if (k == 0 && cap == 0)
            cur[k][cap] = 0.0;
          else
            cur[k][cap] = -1;
          continue;
        }
        
        if (cap >= glass[i - 1].first && k > 0)
          cur[k][cap] = max(prev[k][cap], prev[k - 1][cap - glass[i - 1].first]
                              + glass[i - 1].second);
      }
    prev = cur;
  }


  for (int k = 1; k <= n; ++k) {
    double ans = 0.0;
    for (int cap = 0; cap <= B; ++cap)
      if (cur[k][cap] >= 0)
        ans = max(ans, min((double)cap, cur[k][cap] / 2.0 + B / 2.0));
    printf("%0.9lf ", ans); 
  }
  puts("");
  return 0;
}

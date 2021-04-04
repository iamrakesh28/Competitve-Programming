#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> L;

void solve(int n, int c) {

  L.clear();
  
  int sum = n * (n + 1) / 2 - 1, pos;
  for (int i = 0; i < n - 1; ++i) {
    int min_sum = sum - (n - i) + 1;
    if (c <= sum && c >= min_sum) {

      int ind = i + 3;
      pos = n - (sum - c);

      L.push_back(i + 1);
      
      while (ind <= n) {
        L.push_back(ind);
        ind += 2;
      }

      ind--;
      if (ind > n)
        ind -= 2;
      
      while (ind >= i + 2) {
        L.push_back(ind);
        ind -= 2;
      }

      reverse(L.begin() + i, L.begin() + pos);
      break;
    }
    else {
      L.push_back(i + 1);
      c--;
      sum -= (n - i);
    }
  }

  
  return;
}

int main() {

  int t;
  scanf("%d", &t);

  for (int q = 0; q < t; ++q) {
    int n, c;
    scanf("%d%d", &n, &c);

    int max_cost = n * (n + 1) / 2 - 1, min_cost = n - 1;
    printf("Case #%d: ", q + 1);

    if (c > max_cost || c < min_cost) {
      puts("IMPOSSIBLE");
      continue;
    }

    solve(n, c);
    for (int yi : L)
      printf("%d ", yi);
    puts("");
  }
  
  return 0;
}

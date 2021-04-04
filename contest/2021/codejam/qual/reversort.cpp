#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> L;

int find_min(int i, int n) {

  pair <int, int> min_ind = {1e9, -1};
  for (int j = i; j < n; ++j) {
    min_ind = min(min_ind, make_pair(L[j], j));
  }

  return min_ind.second;
}

int solve(int n) {

  int cost = 0;
  for (int i = 0; i < n - 1; ++i) {
    int ind = find_min(i, n);
    cost += (ind - i + 1);
    reverse(L.begin() + i, L.begin() + ind + 1);
  }

  return cost;
}

int main() {

  int t;
  scanf("%d", &t);

  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%d", &n);

    L.resize(n);
    for (int i = 0; i < n; ++i) {
      int li;
      scanf("%d", &li);
      L[i] = li;
    }

    printf("Case #%d: %d\n", q + 1, solve(n));
  }
  
  return 0;
}

#include <iostream>
#include <set>

using namespace std;
using LL = long long;

const int N = 305, MAX = 2e6 + 1;
int G[N][N], visit;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
set <pair <int, int>> box_height[MAX];

void reset(int max_gi) {

  for (int i = 0; i <= max_gi; ++i)
    box_height[i].clear();
  
  return;
}

bool valid(int i, int j, int r, int c) {
  if (i >= 0 && j >= 0 && i < r && j < c)
    return true;
  return false;
}

LL solve(int val, int r, int c) {

  LL cost = 0;
  for (auto cell : box_height[val]) {
    for (int d = 0; d < 4; ++d) {
      int ri = dr[d] + cell.first, ci = dc[d] + cell.second;
      if (valid(ri, ci, r, c) && abs(G[ri][ci] - G[cell.first][cell.second]) > 1) {

        cost = cost + abs(G[ri][ci] - G[cell.first][cell.second]) - 1;

        box_height[G[ri][ci]].erase(box_height[G[ri][ci]].find({ri, ci}));
        G[ri][ci] = G[cell.first][cell.second] - 1;
        //visit++;
        
        box_height[val - 1].insert({ri, ci});
      }

    }
  }
  
  return cost;
}

int main() {

  int t;
  scanf("%d", &t);

  for (int q = 0; q < t; ++q) {
    int r, c;
    scanf("%d%d", &r, &c);

    int max_gi = 0;
    visit = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        scanf("%d", G[i] + j);
        max_gi = max(max_gi, G[i][j]);
      }
    }

    reset(max_gi);

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        box_height[G[i][j]].insert({i, j});
      }
    }

    LL cost = 0;
    int cells = r * c;
    for (int i = max_gi; i > 0 && visit < cells; i--) {
      //cout << i << " " << box_height[i].size() << endl;
      cost += solve(i, r, c);
    }

    printf("Case #%d: %lld\n", q + 1, cost);
  }
  
  return 0;
}

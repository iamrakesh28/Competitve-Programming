#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

vector <int> cnt;
vector <pair <int, int>> ants;

LL solve(int n) {

  LL collisions = 0;
  sort(ants.begin(), ants.end());

  int i = 0, size = ants.size();
  while (i < size) {

    if (i < size - 1) {
      if (ants[i + 1].first == ants[i].first) {

        collisions++;
        cnt[ants[i].second]--;
        collisions += cnt[ants[i].second];
        
        while (i + 1 < size && ants[i + 1].first == ants[i].first) {
          cnt[ants[i + 1].second]--;
          collisions += cnt[ants[i + 1].second];
          i++;
        }
      }
      else {
        int index = ants[i].second;
        if (index >= n)
          index = index - n;
        else
          index = index + n;

        cnt[ants[i].second]--;
        collisions += cnt[index];
      }
    }
    i++;
  }
  
  return collisions;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    ants.clear();
    cnt.resize(n << 1);
    for (int i = 0; i < (n << 1); ++i)
      cnt[i] = 0;
    
    for (int i = 0; i < n; ++i) {
      int mi;
      scanf("%d", &mi);

      for (int j = 0; j < mi; ++j) {
        int xi;
        scanf("%d", &xi);
        
        if (xi < 0) {
          ants.push_back({-xi, n + i});
          cnt[n + i]++;
        }
        else {
          ants.push_back({xi, i});
          cnt[i]++;
        }
      }
    }

    LL colns = solve(n);
    printf("%lld\n", colns);
  }
  
  return 0;
}

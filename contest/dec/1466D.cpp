#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int>> deg_wi;
vector <long long> k_col;

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    long long sum = 0;
    scanf("%d", &n);

    deg_wi.resize(n);
    k_col.resize(n);

    for (int i = 0; i < n; ++i) {
      deg_wi[i].second = 0;
      int wi;
      scanf("%d", &wi);
      sum += wi;
      deg_wi[i].first = wi;
    }

    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      deg_wi[u - 1].second++, deg_wi[v - 1].second++;
    }

    sort(deg_wi.begin(), deg_wi.end());
    reverse(deg_wi.begin(), deg_wi.end());

    int index = 0;
    for (int i = 0; i < n - 1; ++i) {
      k_col[i] = sum;

      while (index < n && deg_wi[index].second <= 1) {
        index++;
      }

      if (index < n) {
        deg_wi[index].second--;
        sum += deg_wi[index].first;
      }
      
    }
    
    for (int i = 0; i < n - 1; ++i)
      printf("%d ", k_col[i]);
    puts("");
    
  }
  
  return 0;
}

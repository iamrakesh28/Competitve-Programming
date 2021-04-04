#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;

const int N = 2e5 + 5;
pair <int, int> a[N];
LL sum[N];
vector <int> winners;

int find_next(LL pref, int n) {

  int beg = 0, end = n - 1, mid, pos = 0;

  while (beg <= end) {
    mid = (beg + end) >> 1;
    if (a[mid].first <= pref) {
      pos = mid;
      beg = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }

  return pos;
}

bool win(int i, int n) {

  bool poss = false;
  LL pref = sum[i];
  int j = find_next(pref, n);
  
  while (j < n - 1) {
    i = j;
    pref = sum[i];
    j = find_next(pref, n);
    if (i >= j)
      return false;
  }

  return true;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      a[i] = {ai, i};
    }

    sort(a, a + n);
    sum[0] = a[0].first;

    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + a[i].first;
    }

    int beg = 0, end = n - 1, mid, pos = n - 1;

    while (beg <= end) {
      mid = (beg + end) >> 1;
      if (win(mid, n)) {
        pos = mid;
        end = mid - 1;
      }
      else {
        beg = mid + 1;
      }
    }

    winners.clear();
    for (int i = pos; i < n; ++i)
      winners.push_back(a[i].second + 1);

    sort(winners.begin(), winners.end());
    printf("%d\n", winners.size());
    for (int v : winners) {
      printf("%d ", v);
    }
    puts("");
  }
  
  return 0;
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;
int mp[N], deg[N];
pair <int, int> ab[N];

int main() {
  int n;
  scanf("%d", &n);
  vector <int> id(n);
  memset(mp, -1, sizeof mp);
  for (int i = 0; i < n; ++i) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    ab[i] = {ai, bi};
    mp[ai] = bi;
    deg[ai]++;
    deg[bi]++;
  }
  int last = mp[0], cnt = 1;
  //cout << last << endl;
  while (last != -1 && last > 0) {
    id[cnt] = last;
    cnt += 2;
    last = mp[last];
  }
  int first;
  for (int i = 0; i < n; ++i) {
    if (deg[ab[i].first] == 1) {
      first = ab[i].first;
      id[0] = first;
      break;
    }
  }
  //cout << first << endl;
  last = mp[first], cnt = 2;
  while (last != -1 && last > 0) {
    id[cnt] = last;
    cnt += 2;
    last = mp[last];
  }
  for (int v : id)
    printf("%d ", v);
  puts("");
  return 0;
}

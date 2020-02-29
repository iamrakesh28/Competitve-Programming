#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int score[N], nj[N], tj[N], mj[N], B, L, D;
vector <pair<int, int>> lib[N];
vector <int> suff[N], ans;
bool taken[N];

int main() {

  memset(taken, false, sizeof taken);
  scanf("%d%d%d", &B, &L, &D);
  for (int i = 0; i < B; ++i)
    scanf("%d", score + i);
  for (int i = 0; i < L; ++i) {
    scanf("%d%d%d", nj + i, tj + i, mj + i);
    for (int j = 0; j < nj[i]; ++j) {
      int id;
      scanf("%d", &id);
      lib[i].push_back({score[id], id});
    }
    sort(lib[i].begin(), lib[i].end());
    reverse(lib[i].begin(), lib[i].end());
    suff[i].push_back(0);
    int sum = 0, cnt = 0;
    for (auto it : lib[i]) {
      int j = it.second;
      sum += score[j];
      cnt++;
      if (cnt >= mj[i]) {
	suff[i].push_back(sum);
	cnt = 0;
      }
    }
    if (cnt)
      suff[i].push_back(sum);
  }
  for (int i = 0; i < D; ) {
    int val = -1, ind, sign, sc;
    for (int j = 0; j < L; ++j) {
      if (taken[j])
	continue;
      sign = tj[j];
      int rem = D - i - sign;
      int last = suff[j].size();
      if (rem > 0)
	sc = suff[j][last - 1];
      else
	sc = 0;
      if (val < sc) {
	ind = j;
	val = sc;
      }
    }
    taken[ind] = true;
    ans.push_back(ind);
    i += tj[ind];
  }
  printf("%d\n", ans.size());
  for (int v : ans) {
    printf("%d %d\n", v, nj[v]);
    for (auto it : lib[v]) {
      int j = it.second;
      printf("%d ", j);
    }
    puts("");
  }
  return 0;
}

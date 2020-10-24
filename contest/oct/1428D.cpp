#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5 + 5;
int a[N], row[N];
vector <int> ans[N];
set <int> un;

int main() {
  int n, t = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  int prev = n + 1, col = n + 1;
  bool poss = true, one = false;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0)
      continue;
    if (a[i] == 1) {
      prev--;
      ans[i].push_back(prev);
      t++;
      col = i;
      un.insert(prev);
    }
    else if (a[i] == 2) {
      if (one == false)
	poss = false;
      prev--;
      if (un.size()) {
	auto it = un.begin();
	int num = (*it);
	ans[i].push_back(num);
	un.erase(it);
      }
      else
	poss = false;
      col = i;
      t++;
    }
    else {
      if (one == false)
	poss = false;
      prev--;
      ans[i].push_back(prev);
      if (col < n) {
	if (un.find(ans[col][0]) != un.end())
	  un.erase(un.find(ans[col][0]));
	ans[col].push_back(prev);
      }
      t += 2;
      col = i;
    }
    one = true;
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i].size()) {
      for (int r : ans[i]) {
	row[r - 1]++;
	if (row[r - 1] > 2)
	  poss = false;
      }
    }
  }
  if (poss == false) {
    puts("-1");
    return 0;
  }
  printf("%d\n", t);
  for (int i = 0; i < n; ++i) {
    if (ans[i].size()) {
      for (int r : ans[i])
	printf("%d %d\n", r, i + 1);
    }
  }
  return 0;
}

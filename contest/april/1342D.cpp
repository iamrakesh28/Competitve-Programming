#include <iostream>
#include <vector>
#include <set>

typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
int arr[N], c[N];
vector <vector <int>> ans(N);

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int m;
    scanf("%d", &m);
    arr[m - 1]++;
  }
  for (int i = 0; i < k; ++i)
    scanf("%d", c + i);
  int cnt = 0, i = k - 1;
  set <pair <ll, int>> s;
  while (i >= 0) {
    if (arr[i] == 0) {
      i--;
      continue;
    }
    if (s.size()) {
      auto it = s.begin();
      ll sum = (*it).first;
      if (c[i] > sum) {
	int id = (*it).second, j;
	for (j = 0; j < c[i] - sum && j < arr[i]; ++j)
	  ans[id].push_back(i + 1);
	sum += j;
	arr[i] -= j;
	s.erase(it);
	s.insert({sum, id});
      }
      else {
	cnt++;
	ll sum = 0;
	int j;
	for (j = 0; j < c[i] && j < arr[i]; ++j)
	  ans[cnt].push_back(i + 1);
	sum += j;
	arr[i] -= j;
	s.insert({sum, cnt});
      }
    }
    else {
      ll sum = 0;
      int j;
      for (j = 0; j < c[i] && j < arr[i]; ++j)
	ans[cnt].push_back(i + 1);
      sum += j;
      arr[i] -= j;
      s.insert({sum, cnt});
    }
  }
  printf("%d\n", cnt + 1);
  for (int i = 0; i <= cnt; ++i) {
    printf("%d ", ans[i].size());
    for (int j : ans[i])
      printf("%d ", j);
    puts("");
  }
  return 0;
}

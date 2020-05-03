#include <iostream>
#include <set>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int A[N];
set <int> org, pre;
int mark[32];
vector <int> bit[31], rem;

int main() {

  int n, k, ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", A + i);
    for (int j = 0; j < 31; ++j)
      if ((1 << j) & A[i])
	bit[j].push_back(A[i]);
  }
  org.insert(A[k - 1]);
  memset(mark, 0, sizeof mark);
  while (org.size()) {
    rem.clear();
    while (org.size()) {
      auto it = org.begin();
      rem.push_back(*it);
      pre.insert(*it);
      org.erase(it);
      ans++;
      //cout<<(*it)<<endl;
    }
    for (int it : rem)
      for (int j = 30; j >= 0; j--) {
	if (mark[j])
	  continue;
	if ((1 << j) & it)
	  for (auto it1 : bit[j]) {
	    mark[j] = 1;
	    if (it1 == A[k - 1])
	      continue;
	    if (pre.find(it1) != pre.end())
	      continue;
	    org.insert(it1);
	    // cout<<it1<<endl;
	  }
      }
  }
  printf("%d\n", n - ans);
  return 0;
}

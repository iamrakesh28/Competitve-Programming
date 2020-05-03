#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

const int N = 1e4;
struct Query {
  string m, r;
} query[N];

set <int> arr[10];
set <char> alp;
vector <char> al;

int cnt[26];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int u;
    scanf("%d", &u);
    memset(cnt, 0, sizeof cnt);
    alp.clear();
    for (int j = 0; j < 10; ++j) {
      arr[j].clear();
      for (int k = 0; k < 10; ++k)
	arr[j].insert(k);
    }
    for (int j = 0; j < N; ++j) {
      string a, b;
      cin>>a>>b;
      query[j] = {a, b};
      for (char c : b)
	alp.insert(c);
    }
    for (auto it : alp)
      al.push_back(it);
    for (int j = 0; j < N; ++j) {
      string a, b;
      a = query[j].m, b = query[j].r;
      char c = b[0];
      auto f = lower_bound(al.begin(), al.end(), c);
      int pos = f - al.begin();
      if (arr[pos].find(0) != arr[pos].end())
	arr[pos].erase(arr[pos].find(0));
      if (a.length() == b.length()) {
	int d = a[0] - 'A';
	for (int k = d + 1; k < 10; ++k) {
	  if (arr[pos].find(k) != arr[pos].end())
	    arr[pos].erase(arr[pos].find(k));
	}
      }
    }
    string ans = "";
    char ab[11];
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k)
	if (arr[k].find(j) != arr[k].end()) {
	  ans = ans + al[k];
	  arr[k].erase(arr[k].find(j));
	  break;
	}
    }
    printf("Case #%d: ", i + 1);
    cout<<ans<<endl;
  }
  return 0;
}

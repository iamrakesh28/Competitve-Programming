#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int N = 1e5 + 5;
multiset <int> s;
vector <int> ans;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    s.insert(a);
  }
  ans.resize(n);
  int cnt = 0, mx, ind = 0;
  for (int i = 0; i < n;) {
    if (i) {
      auto it = s.end();
      it--;
      int val = *it;
      if (i == n - 1) {
	ans[ind] = val;
	break;
      }
      ans[ind + 1] = val;
      i++;
      s.erase(it);
      it = s.lower_bound(val - 1);
      if (it == s.end())
	it--;
      int num = *it;
      //i++;
      //s.erase(it);
      if (num >= val) {
	if (it == s.begin()) {
	  ans[ind] = num;
	  ind += 2;
	  s.erase(it);
	  for (int v : s)
	    ans[ind++] = v;
	  break;
	}
	else {
	  it--;
	  num = *it;
	  ans[ind] = num;
	  s.erase(it);
	  i++;
	  ind += 2;
	  cnt++;
	}
      }
      else {
	ans[ind] = num;
	s.erase(it);
	i++;
	ind += 2;
      }
    }
    else {
      auto it = s.end();
      it--;
      mx = *it;
      s.erase(it);
      i++;
      ans[ind++] = mx;
    }
  }
  cnt = 0;
  for (int i = 1; i < n; i++) {
    if (i + 1 < n && ans[i - 1] > ans[i] && ans[i] < ans[i + 1]) {
      //cout << "sa";
      cnt++;
    }
  }
  printf("%d\n", cnt);
  for (int v : ans)
    printf("%d ", v);
  puts("");
  return 0;
}

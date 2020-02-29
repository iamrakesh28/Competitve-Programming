#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
multiset <int> pref;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    long long x, ans = 0, temp, sum = 0;
    scanf("%d%lld", &n, &x);
    char ch = getchar();
    pref.clear();
    for (int i = 0; i < n; ++i) {
      ch = getchar();
      if (ch == '0')
	sum++;
      else
	sum--;
      pref.insert(sum);
    }
    ans = ans + pref.count(x);
    if (sum == 0) {
      if (ans)
	ans = -1;
      cout<<ans<<endl;
      continue;
    }
    //cout<<sum<<endl;
    //temp = x - sum;
    for (auto it : pref) {
      //cout<<it<<":"<<endl;
      long long v = x - it;
      if (v % sum)
	continue;
      v = v / sum;
      if (v <= 0)
	continue;
	//cout<<v<<":"<<sum<<";";
      ans++;
    }
    if (x == 0)
      ans++;
    cout<<ans<<endl;
  }
  return 0;
}

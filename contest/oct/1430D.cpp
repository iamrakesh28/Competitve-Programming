#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;
char s[N];
vector <int> res;
int mp[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, cnt = 1, ans = 0;
    res.clear();
    scanf("%d%s", &n, s);
    for (int i = 1; i < n; ++i) {
      if (s[i] != s[i - 1]) {
	res.push_back(cnt);
	cnt = 1;
      }
      else
	cnt++;
    }
    res.push_back(cnt);
    cnt = 0;
    for (int i = 0; i < res.size(); ++i) {
      if (res[i] >= 2)
	cnt += (res[i] - 1);
      mp[i] = res[i];
    }
    int i = 0, cur = 0;
    n = res.size();
    while (i < n) {
      if (cnt) {
	while (cur < i || mp[cur] < 2)
	  cur++;
	cnt--;
	mp[cur]--;
	if (mp[i] >= 2)
	  cnt -= (mp[i] - 1);
	i++;
      }
      else
	i += 2;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char s[100005];
long long cnt[26];
vector <int> alp[26];

long long find(int i, int ind) {
  int beg = 0, end = alp[i].size() - 1, mid;
  long long ans = 0;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    if (alp[i][mid] >= ind) {
      ans = alp[i].size() - mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    alp[s[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; ++i)
    ans = max(ans, (long long)alp[i].size());
  for (int i = 0; i < 26; ++i) {
    int k = 0;
    memset(cnt, 0, sizeof cnt);
    while (k <  alp[i].size()) {
      int ind = alp[i][k] + 1;
      for (int j = 0; j < 26; ++j) {
	long long c = find(j, ind);
	cnt[j] += c;
      }
      k++;
    }
    for (int j = 0; j < 26; ++j)
      ans = max(ans, cnt[j]);
  }
  printf("%lld\n", ans);
  return 0;
}

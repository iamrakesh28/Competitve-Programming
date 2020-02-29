#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 2e5 + 5;
pair <long long, long long> pub[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &pub[i].first);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &pub[i].second);
  sort(pub, pub + n);
  long long sum = 0, ans = 0, cur;
  multiset <long long> s;
  for (int i = 0; i < n; ) {
    if (s.size() == 0) {
      cur = pub[i].first;
      s.insert(pub[i].second);
      sum += pub[i].second;
      i++;
    }
    while (i < n && pub[i].first == cur) {
      s.insert(pub[i].second);
      sum += pub[i].second;
      i++;
    }
    auto it = s.end();
    it--;
    long long rem = *it;
    s.erase(it);
    sum -= rem;
    ans += sum;
    cur++;
  }
  while (s.size()) {
    auto it = s.end();
    it--;
    long long rem = *it;
    s.erase(it);
    sum -= rem;
    ans += sum;
  }
  printf("%lld\n", ans);
  return 0;
}

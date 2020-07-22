#include <cstring>
#include <iostream>

using namespace std;

char S[1005];
int pref[1005];

int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%s", S);
    int n = strlen(S);
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
      if (i)
	pref[i] = pref[i - 1];
      if (S[i] == '1')
	pref[i]++;
    }
    int ans = n - pref[n - 1];
    ans = min(ans, pref[n - 1]);
    for (int i = 0; i < n; ++i) {
      int sum = pref[n - 1] - pref[i];
      int prev = pref[i];
      sum = n - i - 1 - sum;
      ans = min(ans, prev + sum);
    }
    for (int i = 0; i < n; ++i) {
      int sum = pref[n - 1] - pref[i];
      int prev = pref[i];
      prev = i + 1 - prev;
      ans = min(ans, prev + sum);
    }
    printf("%d\n", ans);
  }
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int a[N];
long long st[N];

int find(int i) {
}

int main() {
  int n;
  long long ans = 0, pref = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    pref = pref + a[i];
    st[i] = pref;
  }
  pref = 0;
  for (int i = 0; i < n; ++i) {
    if (i)
      st.erase(st.find(pref));
    int cnt = st.count(pref);
    ans = ans + cnt;
    //cout<<cnt<<" "<<i<<" "<<ans<<endl;
    pref = pref + a[i];
  }
  ans = (long long)n * (n + 1) / 2 - ans;
  printf("%lld\n", ans);
  return 0;
}

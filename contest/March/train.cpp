#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
int M[N];
set <pair <int, pair <int, int>>> st;

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int n, k;
    scanf("%d%d", &n, &k);
    st.clear();
    for (int j = 0; j < n; ++j)
      scanf("%d", M + j);
    for (int j = 0; j < n - 1; ++j) {
      int diff = M[j + 1] - M[j];
      st.insert({diff, {diff, 1}});
    }
    while (k > 0) {
      auto it = st.end();
      it--;
      int org = (*it).second.first, cnt = (*it).second.second;
      k--, cnt++;
      int qt = org / cnt;
      if (qt == 0)
	break;
      else {
	if (org % cnt) {
	  int val = org - (cnt - 1) * qt;
	  qt = max(qt, val);
	  //qt++;
	  //qt = org / cnt;
	  //int val2 = org - cnt * qt;
	}
      }
      st.erase(it);
      //cout<<qt<<" "<<org<<endl;
      st.insert({qt, {org, cnt}});
    }
    auto it = st.end();
    it--;
    int ans = (*it).first;
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}

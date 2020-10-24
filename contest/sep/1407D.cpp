#include <iostream>
#include <stack>

using namespace std;
const int N = 3e5 + 5, inf = 1e9;
int hi[N], dp[N];
stack <int> smin, smax;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", hi + i);
  dp[n - 1] = 0;
  smin.push(n - 1); // 3
  smax.push(n - 1); // 2
  for (int i = n - 2; i >= 0; i--) {
    // max
    dp[i] = dp[i + 1] + 1;
    while (smax.size()) {
      int ind = smax.top();
      int h = hi[ind];
      dp[i] = min(dp[i], dp[ind] + 1);
      if (h <= hi[i]) {
	smax.pop();
	if (h == hi[i])
	  break;
	//stx.erase(stx.find({dp[ind], ind}));
      }
      else
	break;
    }
    smax.push(i);
    //cout << dp[i] << " ";
    // min
    while (smin.size()) {
      int ind = smin.top();
      int h = hi[ind];
      dp[i] = min(dp[i], dp[ind] + 1);
      if (h >= hi[i]) {
	smin.pop();
	if (h == hi[i])
	  break;
	//dp[i] = min(dp[i], dp[ind] + 1);
      }
      else
	break;
    }
    smin.push(i);
    //cout << dp[i] << endl;
  }
  printf("%d\n", dp[0]);
  return 0;
}

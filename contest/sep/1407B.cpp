#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int N = 1e3 + 5;
int a[N];
bool visit[N];
vector <int> ans;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, mx = -1, ind;
    scanf("%d", &n);
    ans.clear();
    for (int i = 0 ; i < n; ++i) {
      scanf("%d", a + i);
      visit[i] = false;
      if (mx < a[i]) {
	ind = i;
	mx = a[i];
      }
    }
    visit[ind] = true;
    int g = mx;
    ans.push_back(mx);
    for (int i = 1; i < n; ++i) {
      int temp = 0;
      for (int j = 0; j < n; ++j) {
	if (visit[j])
	  continue;
	
	int val = __gcd(g, a[j]);
	if (temp < val) {
	  temp = val;
	  ind = j;
	}
      }
      visit[ind] = true;
      ans.push_back(a[ind]);
    }
    for (int b : ans)
      printf("%d ", b);
    puts("");
  }
  return 0;
}

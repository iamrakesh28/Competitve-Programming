#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3 + 5;
int a[N], pres[N], inv[N];
vector <int> step;

int mex(int n) {
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (pres[i] == 0) {
      ans = i;
      break;
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int k = 0, n;
    scanf("%d", &n);
    step.clear();
    for (int i = 0; i <= n; ++i)
      pres[i] = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      pres[a[i]]++;
    }
    int val = mex(n);
    while (val < n) {
      pres[val]++;
      int temp = a[val];
      a[val] = val;
      pres[temp]--;
      //cout<<val<<" ";
      k++;
      step.push_back(val);
      val = mex(n);
    }

    for (int i = 0; i < n; ++i)
      inv[a[i]] = i;
    
    for (int i = 0; i < n; ++i) {
      if (a[i] == i)
	continue;
      val = mex(n);
      if (val == i) {
	pres[a[i]]--;
	inv[i] = i;
	pres[val]++;
	k++;
	a[i] = i;
	step.push_back(i);
	continue;
      }
      int v = inv[i];
      inv[i] = i;
      inv[val] = v;
      k++;
      step.push_back(v);
      pres[a[v]]--;
      a[v] = val;
      pres[val]++;
      k++;
      pres[a[i]]--;
      a[i] = i;
      pres[i]++;
      step.push_back(i);
    }
    
    printf("%d\n", k);
    for (int v : step)
      printf("%d ", v + 1);
    puts("");
  }
  return 0;
}

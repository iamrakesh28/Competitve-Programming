#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 1e5 + 5, mx = 1e7 + 5;
int A[N], pres[mx << 1];
vector <int> sq, vec;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i * i <= mx; ++i)
    sq.push_back(i * i);
  for (int j = 0; j < t; ++j) {
    int n, sum = 0, maxm = -1;
    scanf("%d", &n);
    vec.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", A + i);
      sum += A[i];
      maxm = max(maxm, sum);
      //s.insert(sum);
      pres[mx + sum]++;
      vec.push_back(sum);
    }
    sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int temp;
      for (auto it : sq) {
	if (it + sum > maxm)
	  break;
	temp = it + sum;
	ans = ans + pres[temp + mx];//s.count(temp);
      }
      sum += A[i];
      pres[sum + mx]--;
      //s.erase(s.find(sum));
      //cout<<ans<<endl;
    }
    for (auto it : vec)
      pres[it + mx] = 0;
    printf("Case #%d: %lld\n", j + 1, ans);
  }
  return 0;
}

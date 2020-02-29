#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5, size = 6e6 + 15;
int ai[N];
pair <int, int> diff[N];
bool isPrime[size];
vector <int> pr;

void prime(int n) {
  memset(isPrime, true, sizeof(bool) * n);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i)
	isPrime[j] = false;
    }
  }
  for (int i = 2; i <= n; ++i)
    if (isPrime[i])
      pr.push_back(i);
  return;
}

int next(int num, int n) {
  int beg = 0, end = n, mid, ans;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    if (pr[mid] >= num) {
      ans = pr[mid];
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  prime(6e6 + 15);
  while (q--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", ai + i);
      //cout<<pr.size()<<endl;
      int nex = next(ai[i], pr.size());
      diff[i] = {nex - ai[i], i};
    }
    sort(diff, diff + n);
    for (int i = 0; i < n; ++i)
      printf("%d ", diff[i].second + 1);
    puts("");
  }
  return 0;
}

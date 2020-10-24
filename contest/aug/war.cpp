#include <iostream>

using namespace std;

const int N = 1e6 + 5, inf = 1e9 + 1;
int A[N], mx = -1;
int temp[N];

bool poss(int d, int n, int y) {
  int cnt = 0, ind;
  long long val;
  bool fo = true;
  for (int i = 0; i <= n; ++i)
    temp[i] = 0;
  for (int i = 1; i <= n; ++i) {
    temp[i] = temp[i - 1];
    if (A[i - 1] <= y)
      temp[i]++;
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] <= y)
      continue;
    int l, r;
    l = i - d;
    r = i + d;
    l = max(0, l);
    r = min(n - 1, r);
    cnt = temp[r + 1] - temp[l];
    val = y;
    val = val * cnt;
    // if (y == 4) {
    //  cout << A[i] << " " << val << " " << cnt<<endl;
    ///} 
    if (A[i] > val) {
      fo = false;
      break;
    }
  }
  //if (y == 4) {
  //  for (int i = 0; i <= n; ++i)
  //    cout << temp[i] << " ";
  //  puts("");
  //}
  //cout << y << " " << cnt << " " << mx << endl;
  return fo;
}

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", A + i);
    mx = max(A[i], mx);
  }
  int beg = 1, end = inf, mid, ans = inf;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    //cout << mid << endl;
    if (poss(d, n, mid)) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}

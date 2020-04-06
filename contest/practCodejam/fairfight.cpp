#include <iostream>

#define DEBUG

using namespace std;

const int N = 1e5, K = 17;
int C[N], D[N], stc[N][K], ste[N][K], logn[N + 1];

void sparse(int n) {
  for (int i = 0; i < n; ++i) {
    stc[i][0] = C[i];
    ste[i][0] = D[i];
  }
  
  for (int j = 1; j <= K; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i) {
      stc[i][j] = max(stc[i][j - 1], stc[i + (1 << (j - 1))][j - 1]);
      ste[i][j] = max(ste[i][j - 1], ste[i + (1 << (j - 1))][j - 1]);
    }
}

int rightEq(int st[][K], int val, int l, int n) {
  int beg = l, end = n - 1, mid, ans = -1;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    int j = logn[mid - beg + 1];
    int mini = min(st[beg][j], st[mid - (1 << j) + 1][j]);
    if (mini <= val) {
      ans = mid;
      beg = mid + 1;
    }
    else
      end = mid - 1;
  }
  return ans;
}

int leftEq(int st[][K], int val, int l) {
  int beg = 0, end = l - 1, mid, ans = -1;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    int j = logn[mid - beg + 1];
    int mini = min(st[beg][j], st[mid - (1 << j) + 1][j]);
    if (mini <= val) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int left(int st[][K], int val, int l) {
  int beg = 0, end = l, mid, ans = -1;
  while (beg <= end) {
    mid = (beg + end) >> 1;
    int j = logn[mid - beg + 1];
    int mini = min(st[beg][j], st[mid - (1 << j) + 1][j]);
    if (mini < val) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int main() {
  
  #ifdef DEBUG
  freopen("test", "r", stdin);
  #endif

  logn[1] = 0;
  for (int i = 0; i <= N; ++i)
    logn[i] = logn[i / 2] + 1;
  int q;
  scanf("%d", &q);
  for (int m = 0; m < q; ++m) {
    int n, k;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (int j = 0; j < n; ++j)
      scanf("%d", C + j);
    for (int j = 0; j < n; ++j)
      scanf("%d", D + j);
    sparse(n);
    for (int i = 0; i < n; ++i) {
      int rc, rd, lc, ld, rdk, ldk, l, r;
      rc = rightEq(stc, C[i], i, n);
      lc = left(stc, C[i], i);
      rd = rightEq(ste, C[i] + k, i, n);
      ld = leftEq(ste, C[i] + k, i);
      rdk = rightEq(ste, C[i] - k, i, n);
      ldk = leftEq(ste, C[i] - k, i);
      cout<<lc<<" "<<rc<<" "<<rd<<" "<<ld<<" "<<rdk<<" "<<ldk<<endl;
      if (lc == -1 || ld == -1 || rdk == -1 || ldk == -1)
	continue;
      l = max(lc, ld);
      r = min(rc, rd);
      l = max(l, ldk);
      r = min(r, rdk);
      ans = ans + (long long)(i - l + 1) * (r - i + 1);
    }
    printf("Case #%d: %d\n", m + 1, ans);
  }
  return 0;
}

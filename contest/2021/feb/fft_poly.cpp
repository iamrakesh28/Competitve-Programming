#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int PRIME = 998244353;
const int root = 565042129; // 3 ^ c where c = (PRIME - 1) / (1 << 20)
const int root_inv = 950391366;
const int root_pw = 1 << 20;

int mod_inverse(int a, int n = PRIME - 2) {

  int r = 1;
  while (n > 0) {
    if (n & 1)
      r = 1LL * r * a % PRIME;
    a = 1LL * a * a % PRIME;
    n >>= 1;
  }

  return r;
}

void fft(vector <int> &a, bool invert) {

  int n = a.size();

  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) {
      j ^= bit;
    }
    j ^= bit;

    if (i < j) {
      swap(a[i], a[j]);
    }
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_inv : root;

    for (int i = len; i < root_pw; i <<= 1) {
      wlen = (LL)wlen * wlen % PRIME;
    }

    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < (len >> 1); ++j) {
        int u = a[i + j], v = (LL)a[i + j + len / 2] * w % PRIME;
        a[i + j] = u + v < PRIME ? u + v : u + v - PRIME;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + PRIME;
        w = (LL)w * wlen % PRIME;
      }
    }
  }

  if (invert) {
    int inv = mod_inverse(n);
    for (int &x : a) {
      x = 1LL * x * inv % PRIME;
    }
  }
  
}

vector <int> multiply(vector <int> const& a, vector <int> const& b) {

  vector <int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size())
    n <<= 1;

  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);

  for (int i = 0; i < n; ++i) {
    fa[i] = (LL)fa[i] * fb[i] % PRIME;
  }

  fft(fa, true);

  return fa;
  
}

int main() {

  vector <int> a{0, 2, 3}, b{0, 1, 0, 3};
  vector <int> poly = multiply(a, b);

  for (int x : poly)
    cout << x << " ";
  cout << endl;
  return 0;
}

#include <iostream>
#include <vector>

typedef long long LL;
using namespace std;

const int N = 2e5 + 5;
const int BIT = 30;

const int PRIME = 998244353;
/*
 * primitive root of PRIME
 3 ^ c where c = (PRIME - 1) / (1 << 20)
*/
const int root = 565042129;
const int root_inv = 950391366;
const int root_pw = 1 << 20;

int bit_count[BIT], inv_fact[N], factorial[N], prefix[BIT][N];

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

int choose(int n, int k) {
  
  int nC = (LL)factorial[n] * inv_fact[k] % PRIME;
  nC = (LL)nC * inv_fact[n - k] % PRIME;

  return nC;
}

void preprocess(int n) {

  factorial[0] = 1;
  inv_fact[0] = mod_inverse(factorial[0]);
  for (int i = 1; i <= n; ++i) {
    factorial[i] = (LL)factorial[i - 1] * i % PRIME;
    inv_fact[i] = mod_inverse(factorial[i]);
  }


  for (int i = 0; i < BIT; ++i) {

    vector <int> a, b;
    int cnt = bit_count[i];

    // cout << "bit: " << cnt << " " << i + 1 << endl;
    // odd powers
    a.push_back(0);
    
    for (int j = 1; j <= n; ++j) {
      if (j > cnt)
        break;
      if (j & 1) {
        a.push_back(choose(cnt, j));
      }
      else
        a.push_back(0);
    }

    // all powers of zero bits
    b.push_back(1);
    cnt = n - cnt;
    
    for (int j = 1; j <= n; ++j) {
      if (j > cnt)
        break;
      b.push_back(choose(cnt, j));
    }

    vector <int> poly = multiply(a, b);

    prefix[i][0] = 0;
    for (int j = 1; j <= n; ++j) {
      prefix[i][j] = ((LL)prefix[i][j - 1] + poly[j]) % PRIME;
    }
    
  }

  return;
}

int main() {

  int n, q;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int ai;
    scanf("%d", &ai);
    for (int j = 0; j < BIT; ++j) {
      if (ai & (1 << j))
        bit_count[j]++;
    }
  }
  
  preprocess(n);

  scanf("%d", &q);

  while (q--) {
    int m;
    scanf("%d", &m);

    int carry = 1, ans = 0;
    for (int j = 0; j < BIT; ++j) {
      int pref = (LL)prefix[j][m] * carry % PRIME;
      ans = ((LL)ans + pref) % PRIME;
      carry <<= 1;
    }

    printf("%d\n", ans);
  }
  
  return 0;
}

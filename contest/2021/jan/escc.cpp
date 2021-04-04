#include <iostream>
#include <vector>

typedef long long LL;
using namespace std;

const int prime = 998244353;

LL modInverse(LL a, LL n = prime - 2) {

  LL r = 1;
  while (n > 0) {
    if (n & 1)
      r = a * r % prime;
    a = a * a % prime;
    n >>= 1;
  }
  
  return r;
}

void sub(pair <LL, LL> &cur, pair <LL, LL> &prev, LL prob, LL invK) {

  // same color
  LL prod = invK * prob % prime;
  LL diff = prev.second * prod % prime;

  cur.first = (cur.first - diff + prime) % prime;
  cur.first = (cur.first + prev.first * prod % prime) % prime;
      
  cur.second = (cur.second + diff) % prime;
  
  return;
}

void same(pair <LL, LL> &cur, pair <LL, LL> &prev, LL invK) {

  // same color
  cur.first = (cur.first + prev.first * invK % prime) % prime;
  cur.second = (cur.second + prev.second * invK % prime) % prime;
  
  return;
}

void diff(pair <LL, LL> &cur, pair <LL, LL> &prev, LL prob, LL invK) {

  // diff color
  LL prod = invK * prob % prime;
  LL diff = prev.second * prod % prime;

  cur.first = (cur.first + diff) % prime;
  cur.first = (cur.first + prev.first * prod % prime) % prime;
      
  cur.second = (cur.second + diff) % prime;

  return;
}

int main() {

  int m, n, k;
  cin >> m >> n >> k;

  LL ans = 0, invK = modInverse(k);

  // cout << 3 * modInverse(27) % prime << endl;
  if (m == 1) {
    vector <pair<LL, LL>> dp(n);

    dp[0] = {1, 1};
    for (int i = 1; i < n; ++i) {
      dp[i] = {0, 0};
      same(dp[i], dp[i - 1], invK);
      diff(dp[i], dp[i - 1], k - 1, invK);
    }

    ans = dp[n - 1].first;
  }
  else {
    
    vector <vector <vector <pair <LL, LL>>>>
      dp(2, vector <vector <pair <LL, LL>>> (n, vector <pair <LL, LL>> (3)));

    LL temp = (k - 1) * invK % prime;
    dp[1][0][0] = {invK, invK};
    dp[1][0][1] = {2 * temp % prime, temp};
    
    for (int i = 1; i < n; ++i) {
      
      dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = {0, 0};

      // 0 -> (a, b, b), 2 -> (a, a, a)
      // m = 0
      same(dp[0][i][2], dp[1][i - 1][0], invK);
      diff(dp[0][i][0], dp[1][i - 1][1], 1, invK);

      diff(dp[0][i][1], dp[1][i - 1][0], k - 1, invK);
      same(dp[0][i][1], dp[1][i - 1][1], invK);
      
      if (k >= 2)
        diff(dp[0][i][1], dp[1][i - 1][1], k - 2, invK);

      // m = 1
      dp[1][i][0] = dp[1][i][1] = {0, 0};

      same(dp[1][i][0], dp[0][i][2], invK);
      sub(dp[1][i][0], dp[0][i][0], 1, invK);
      same(dp[1][i][0], dp[0][i][1], invK);

      diff(dp[1][i][1], dp[0][i][0], k - 1, invK);
      diff(dp[1][i][1], dp[0][i][2], k - 1, invK);
      same(dp[1][i][1], dp[0][i][1], invK);

      if (k >= 2)
        diff(dp[1][i][1], dp[0][i][1], k - 2, invK);
    }

    // cout << dp[1][1][0].second << " " << dp[1][1][1].second << endl;
    ans = (dp[1][n - 1][0].first + dp[1][n - 1][1].first) % prime;

  }

  cout << ans << endl;
  return 0;
}

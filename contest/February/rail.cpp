#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

#define ind(x)  (x + 100005)

using namespace std;

const int N = 1e5 + 5;
bool visit[N], sy[N << 1], sx[N << 1];
int x[N], y[N];
vector <int> prime;
vector <int> newfact[N];
vector <pair <int, int>> fact[N];

void sieve(int n) {
  memset(visit, true, sizeof visit);
  visit[0] = visit[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (visit[i] == false)
      continue;
    for (int j = i * i; j <= n; j += i)
      visit[j] = false;
  }
  for (int i = 2; i <= n; ++i)
    if (visit[i])
      prime.push_back(i);
  //for (int it : prime)
  // cout<<it<<endl;
  return;
}

void factor(int n) {
  for (int i = 2; i <= n; ++i) {
    int size = 0;
    long long num = (long long)i * i;
    for (int p : prime) {
      if ((long long)p * p > num)
	break;
      if (num % p == 0) {
	assert(p > 0);
	fact[i].push_back({p, 1});
	size++;
	num = num / p;
	while (num % p == 0) {
	  fact[i][size - 1].second++;
	  num = num / p;
	}
      }
    }
    if (num > 1)
      fact[i].push_back({num, 1});
    //for (auto it : fact[i])
    // cout<<i<<" "<<it.first<<" "<<it.second<<endl;
  }
  return;
}

int find(int val, long long num, bool * r) {
  if (r[ind(val)] == false)
    return 0;
  val = num / val;
  val = -val;
  if (r[ind(val)] == false)
    return 0;
  //cout<<val<<" "<<num<<endl;
  return 1;
}

void backtrack(int num, int i, int n, long long val) {

  if (i == n) {
    long long temp = (long long)num * num;
    temp = temp / val;
    if (temp > N)
      return;
    newfact[num].push_back(val);
    return;
  }

  long long times = 1;
  for (int j = 0; j <= fact[num][i].second; ++j) {
    if (val * times > N)
      return;
    assert(val * times > 0);
    backtrack(num, i + 1, n, val * times);
    times = times * fact[num][i].first;
  }
  return;
}

void calFact(int n) {
  for (int i = 1; i <= n; ++i) {
    backtrack(i, 0, fact[i].size(), 1);
    //for (int it : newfact[i])
    //cout<<it<<" "<<i<<endl;
  }
  return;
}

int solve(int num, bool *r) {
  int cnt = 0;
  for (int it : newfact[num]) {
    long long temp = (long long)num * num;
    cnt += find(it, temp, r);
  }
  return cnt;
}

int main() {
  int total = N - 3, q;
  sieve(total);
  factor(total);
  calFact(total);
  //cout<<backtrack(6, 0, fact[6].size(), 1)<<endl;
  scanf("%d", &q);
  while (q--) {
    int n, m, ci;
    long long ans = 0;
    memset(sx, false, sizeof sx);
    memset(sy, false, sizeof sy);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &ci);
      if (ci == 0) {
	n--, i--;
	ans = (long long)n * m;
	continue;
      }
      x[i] = ci;
      sx[ind(ci)] = true;
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d", &ci);
      if (ci == 0) {
	m--, i--;
	ans = (long long)n * m;
	continue;
      }
      y[i] = ci;
      sy[ind(ci)] = true;
    }
    
    for (int i = 0; i < n; ++i) {
      int xi = abs(x[i]);
      //cout<<": "<<xi<<endl;
      ans += solve(xi, sy);
    }

    for (int i = 0; i < m; ++i) {
      int xi = abs(y[i]);
      //cout<<": "<<xi<<endl;
      ans += solve(xi, sx);
    }
   
    printf("%lld\n", ans);
  }
  return 0;
}

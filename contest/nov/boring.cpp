#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
char L[20], R[20];
ll dp[20][2];

ll solve(int i, int rem, char num[]) {
  if (i == n)
    return 1;
  if (dp[i][rem] == -1) {
    if (rem)
      dp[i][rem] = 5 * solve(i + 1, rem, num);
    else {
      int tot = num[i] - '0';
      dp[i][rem] = 0;
      if (i & 1) {
	if (tot & 1)
	  tot = (tot >> 1) + 1;
	else
	  tot = tot >> 1;
	if (((num[i] - '0') & 1) == 0)
	  dp[i][rem] += solve(i + 1, 0, num);
      }
      else {
	tot = tot >> 1;
	if ((num[i] - '0') & 1)
	  dp[i][rem] += solve(i + 1, 0, num);
      }
      dp[i][rem] += tot * solve(i + 1, 1, num);
    }
  }
  return dp[i][rem];
}

bool isboring(char L[], int n) {
  bool bore = true;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      if ((L[i] - '0') & 1)
	bore = false;
    }
    else
      if (((L[i] - '0') & 1) == 0)
	bore = false;
  }
  return bore;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    scanf("%s%s", L, R);
    n = strlen(R);
    ll upper = 0, lower = 0, temp = 1;
    memset(dp, -1, sizeof dp);
    upper += solve(0, 0, R);
    // cout << upper << endl;
    for (int i = 1; i < n; ++i) {
      temp = 1;
      for (int j = 0; j < i; ++j)
	temp = temp * 5;
      upper += temp;
    } 
    n = strlen(L);
    memset(dp, -1, sizeof dp);
    lower += solve(0, 0, L);
    // cout << lower << endl;
    for (int i = 1; i < n; ++i) {
      temp = 1;
      for (int j = 0; j < i; ++j)
	temp = temp * 5;
      lower += temp;
    }
    int c = 0;
    if (isboring(L, n))
      c++;
    printf("Case #%d: %lld\n", q + 1, upper - lower + c);
  }
  return 0;
}

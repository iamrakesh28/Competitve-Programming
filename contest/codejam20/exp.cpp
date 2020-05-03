#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 31;
int dp[N][N][2];
vector <char> ans;

int bit(int num) {
  int cnt = 0;
  while (num) {
    num = num & (num - 1);
    cnt++;
  }
  return cnt;
}

int getnum(int num, int i, int j) {
  int a = 0;
  for (int c = i; c >= j; c--) {
    if (num & (1 << c))
      a = a | (1 << c);
  }
  return a;
}

void solve(int x, int y, int n) {
  for (int i = n; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int a = getnum(x, i, j);
      int b = getnum(y, i, j);
      int xo = a ^ b;
      int cnt = bit(xo);
      if (cnt == i - j + 1) {
	dp[i][j][0] = 1;
	dp[i][j][1] = -1;
	continue;
      }
      dp[i][j][0] = dp[i][j][1] = -1;
      cnt = i + 1;
      if ((1 << cnt) & x)
	continue;
      if ((1 << cnt) & y)
	continue;
      if ((1 << j) & x) {
	if ((1 << j) & y) {
	  //cout<<i<<" "<<j<<endl;
	  continue;
	}
	int x1 = (1 << (i - j + 1)) - 1;
	x1 = x1 ^ a;
	x1 = x1 | (1 << j);
	xo = x1 ^ b;
	cnt = bit(xo);
	if (cnt == i - j + 1)
	  dp[i][j][1] = 0;
	continue;
      }
      if ((1 << j) & y) {
	int x1 = (1 << (i - j + 1)) - 1;
	x1 = x1 ^ b;
	x1 = x1 ^ (1 << j);
	xo = x1 ^ a;
	cnt = bit(xo);
	if (cnt == i - j + 1)
	  dp[i][j][1] = 1;
	continue;
      }
      
    }
  }
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    int lbit, x1 = abs(x), y1 = abs(y);
    for (int j = N; j >= 0; j--) {
      if ((1 << j) & x1) {
	lbit = j;
	break;
      }
      if ((1 << j) & y1) {
	lbit = j;
	break;
      }
    }
    solve(x1, y1, lbit);
    int cur, nxt, poss = -1;
    cur = lbit;
    ans.clear();
    while (cur >= 0) {
      poss = -1;
      int j;
      for (j = cur; j >= 0; --j) {
	if (dp[cur][j][0] != -1) {
	  poss = 0;
	  break;
	}
	if (dp[cur][j][1] != -1) {
	  poss = dp[cur][j][1] + 1;
	  break;
	}
      }
      //cout<<dp[1][0][1]<<endl;
      //cout<<poss<<" "<<cur<<" "<<j<<endl;
      if (poss == -1)
	break;
      if (poss == 0) {
	for (int k = cur; k >= j; k--) {
	  if ((1 << k) & x1)
	    ans.push_back('E');
	  else
	    ans.push_back('N');
	}
      }
      else if (poss == 1) {
	ans.push_back('E');
	for (int k = cur; k > j; k--) {
	  if ((1 << k) & x1)
	    ans.push_back('N');
	  else
	    ans.push_back('W');
	}
	ans.push_back('W');
      }
      else {
	ans.push_back('N');
	for (int k = cur; k > j; k--) {
	  if ((1 << k) & y1)
	    ans.push_back('E');
	  else
	    ans.push_back('S');
	}
	ans.push_back('S');
      }
      cur = j - 1;
    }
    printf("Case #%d: ", i + 1);
    if (poss == -1) {
      puts("IMPOSSIBLE");
      continue;
    }
    if (x < 0) {
      for (int j = 0; j < ans.size(); ++j) {
	if (ans[j] == 'W')
	  ans[j] = 'E';
	else if (ans[j] == 'E')
	  ans[j] = 'W';
      }
    }
    if (y < 0) {
      for (int j = 0; j < ans.size(); ++j) {
	if (ans[j] == 'S')
	  ans[j] = 'N';
	else if (ans[j] == 'N')
	  ans[j] = 'S';
      }
    }
    reverse(ans.begin(), ans.end());
    for (char c : ans)
      putchar(c);
    puts("");
  }
  return 0;
}


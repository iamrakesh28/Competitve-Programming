#include <iostream>
#include <vector>

using namespace std;
const int N = 1e6 + 5;

vector <char> mat[N];

int solve2(int m, int bit) {
  int temp = 0;
  for (int i = 0; i < m; ++i) {
    int val = mat[0][i] - '0';
    val += mat[1][i] - '0';
    val = val % 2;
    if (bit) {
      if (val == 0)
	temp++;
    }
    else  {
      if (val)
	temp++;
    }
    bit = 1 - bit;
  }
  return temp;
}

int cost(char *a, char *b) {
  int temp = 0;
  if (a[0] != b[0])
    temp++;
  if (a[1] != b[1])
    temp++;
  if (a[2] != b[2])
    temp++;
  return temp;
}
int solve3(int m, char *a, char *inva, char *b, char *invb) {
  int temp = 0, bit = 0;
  char arr[] = "abc";
  for (int i = 0; i < m; ++i) {
    int val;
    if (bit) {
      val = min(cost(), cost());
    }
    else  {
      if (val)
	temp++;
    }
    temp += val;
    bit = 1 - bit;
  }
  return temp;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n >= 4 && m >= 4) {
    puts("-1");
    return 0;
  }
  if (n == 1 || m == 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char ch;
      scanf(" %c", &ch);
      if (n > m)
	mat[m - j - 1].push_back(ch);
      else
	mat[i].push_back(ch);
    }
  if (n == 2 || m == 2) {
    int ans = min(solve2(max(n, m), 0), solve2(max(n, m), 1));
    printf("%d\n", ans);
    return 0;
  }
  else {
  }
  return 0;
}

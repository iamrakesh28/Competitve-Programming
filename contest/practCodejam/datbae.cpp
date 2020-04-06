#include <iostream>
#include <vector>

using namespace std;

const int N = 1025, bit = 1 << 4;
char test[4][N], result[4][N];
vector <int> ans;

int main() {
  int q, pos = 0, exp;
  scanf("%d", &q);
  while (pos < N - 1) {
    int num = pos % bit;
    for (int i = 0; i < 4; ++i)
      if (num & (1 << i))
	test[i][pos] = '1';
      else
	test[i][pos] = '0';
    pos++;
  }
  for (int i = 0; i < q; ++i) {
    int n, b, f;
    scanf("%d%d%d", &n, &b, &f);
    ans.clear();
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < n; ++k)
	putchar(test[j][k]);
      puts("");
    }
    fflush(stdout);
    for (int j = 0; j < 4; ++j)
      scanf("%s", result[j]);
    pos = 0, exp = 0;
    int ind = 0;
    while (pos < n - b) {
      int num = 0;
      for (int k = 0; k < 4; ++k)
	if (result[k][pos] - '0')
	  num = num | (1 << k);
      while (num != exp) {
	//cout<<num<<" "<<exp<<endl;
	ans.push_back(ind);
	exp = (exp + 1) % bit;
	ind++;
      }
      exp = (exp + 1) % bit;
      pos++;
      ind++;
    }
    while (ind < n)
      ans.push_back(ind++);
    for (int it : ans)
      printf("%d ", it);
    puts("");
    fflush(stdout);
    int nxt;
    if (i < q - 1)
      scanf("%d", &nxt);
    if (nxt == -1)
      return 0;
  }
  return 0;
}

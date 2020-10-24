#include <iostream>
#include <vector>

using namespace std;

const int N = 205;
char mat[N][N];
vector <pair <int, int>> ci;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    ci.clear();
    for (int i = 0; i < n; ++i)
      scanf("%s", mat[i]);
    if (mat[n - 1][n - 3] == mat[n - 2][n - 2] && mat[n - 1][n - 3] == mat[n - 3][n - 1]) {
      char ch = mat[n - 1][n - 3];
      if (mat[n - 1][n - 2] == ch)
	ci.push_back({n, n - 1});
      if (mat[n - 2][n - 1] == ch)
	ci.push_back({n - 1, n});
    }
    else {
      if (mat[n - 1][n - 2] == mat[n - 2][n - 1]) {
	char ch = mat[n - 1][n - 2];
	if (mat[n - 1][n - 3] == ch)
	  ci.push_back({n, n - 2});
	if (mat[n - 2][n - 2] == ch)
	  ci.push_back({n - 1, n - 1});
	if (mat[n - 3][n - 1] == ch)
	  ci.push_back({n - 2, n});
      }
      else {
	int dr[] = {0, -1, -2}, dc[] = {-2, -1, 0};
	char ch = '1';
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < 3; i++) {
	  int r = dr[i] + n - 1, c = dc[i] + n - 1;
	  if (mat[r][c] == '1')
	    cnt1++;
	  else
	    cnt0++;
	}
	if (cnt0 > cnt1)
	  ch = '0';

	for (int i = 0; i < 3; i++) {
	  int r = dr[i] + n - 1, c = dc[i] + n - 1;
	  if (mat[r][c] != ch)
	    ci.push_back({r + 1, c + 1});
	}

	if (mat[n - 1][n - 2] == ch)
	  ci.push_back({n, n - 1});
	if (mat[n - 2][n - 1] == ch)
	  ci.push_back({n - 1, n});
      }
    }
    printf("%d\n", ci.size());
    for (auto it : ci)
      printf("%d %d\n", it.first, it.second);
  }
  return 0;
}

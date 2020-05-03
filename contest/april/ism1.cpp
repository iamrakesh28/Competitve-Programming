#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 5, M = 18;
int bin[N][M];
vector <int> x;

int main() {
  int n, l, q;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int xi;
    scanf("%d", &xi);
    x.push_back(xi);
  }
  scanf("%d%d", &l, &q);
  for (int i = 0; i < n; ++i) {
    auto it = upper_bound(x.begin(), x.end(), x[i] + l);
    it--;
    bin[i][0] = it - x.begin();
    //cout<<bin[i][0]<<endl;
  }
  for (int j = 1; j < M; ++j)
    for (int i = 0; i < n; ++i) {
      int l = bin[i][j - 1], r;
      r = bin[l][j - 1];
      bin[i][j] = r;
    }
  while (q--) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    ai--, bi--;
    int te = min(ai, bi);
    bi = max(ai, bi);
    ai = te;
    int ans = n, prev = ai, temp = 0;
    for (int i = M - 1; i >= 0; i--) {
      int val = bin[prev][i];
      //cout<<prev<<" "<<i<<" "<<val<<" ";
      if (val >= bi) {
	ans = temp | (1 << i);
	//cout<<i<<" ";
	continue;
      }
      temp = temp | (1 << i);
      prev = val;
    }
    printf("%d\n", ans);
  }
  return 0;
}

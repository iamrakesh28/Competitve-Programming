#include <iostream>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
char S[N], T[N];
ll dist[26][26];

int main() {
  int n, K;
  scanf("%d%d", &n, &K);
  scanf("%s%s", S, T);
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < K; ++j)
      scanf("%d", dist[i] + j);
  for (int k = 0; k < K; ++k)
    for (int i = 0; i < K; ++i)
      for (int j = 0; j < K; ++j)
	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += dist[S[i] - 'a'][T[i] - 'a'];
  printf("%lld\n", ans);
  return 0;
}

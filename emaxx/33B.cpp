#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int dist[26][26];
char A[100005], B[100005], C[100005];

int main()
{
	scanf("%s%s", A, B);
	int n;
	scanf("%d", &n);
	int lenA = strlen(A), lenB = strlen(B);
	if (lenA != lenB) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = inf;
	while (n--) {
		char a, b;
		int w;
		scanf(" %c %c%d", &a, &b, &w);
		dist[a - 'a'][b - 'a'] = min(dist[a - 'a'][b - 'a'], w);
	}
	for (int k  = 0; k < 26; ++k)
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < 26; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int ans = 0;
	for (int i = 0; i < lenA; ++i) {
		if (A[i] == B[i]) {
			C[i] = A[i];
			continue;
		}
		int cost = inf;
		char c;
		for (char a = 'a'; a <= 'z'; ++a) {
			if (dist[A[i] - 'a'][a - 'a'] + dist[B[i] - 'a'][a - 'a'] < cost) {
				cost = dist[A[i] - 'a'][a - 'a'] + dist[B[i] - 'a'][a - 'a'];
				c = a;
			}
		}
		if (cost == inf) {
			printf("-1\n");
			return 0;
		}
		ans += cost;
		C[i] = c;
	}
	printf("%d\n%s\n", ans, C);
	return 0;
}

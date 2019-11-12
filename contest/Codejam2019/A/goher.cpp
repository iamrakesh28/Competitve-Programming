#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int & x, int & y) 
{
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}

int coprime[] = {3, 4, 5, 7, 11, 13, 17};

int solve()
{
	int ans = 0, m = 1, inv[7], eq[7];
	for (int i = 0; i < 7; ++i) {
		eq[i] = 0;
		for (int j = 0; j < 18; j++)
			printf("%d ",coprime[i]);
		putchar('\n');
		fflush(stdout);
		for (int j = 0; j< 18; ++j) {
			int x;
			scanf("%d", &x);
			eq[i] += x;
		}
		eq[i] %= coprime[i];
		m *= coprime[i];
	}
	for (int i = 0; i < 7; ++i) {
		int x, y, d;
		d = gcd(m / coprime[i], coprime[i], x, y);
		x = (x + coprime[i]) % coprime[i];
		ans += eq[i] * (m / coprime[i]) * x;
	}
	ans %= m;
	return ans;
	
}

int main()
{
	int q, n, m;
	scanf("%d%d%d", &q, &n, &m);
	while (q--) {
		printf("%d\n",solve());
		fflush(stdout);
		scanf("%d",&n);
		if (n == -1)
			return 0;
	}
	return 0;
}

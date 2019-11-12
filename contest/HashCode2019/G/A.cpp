#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, r;
	scanf("%d%d%d",&n, &m, &r);
	int a = 2000, b = -1;
	for (int i = 0; i < n; ++i) {
		int d;
		scanf("%d",&d);
		a = min(a, d);
	}
	for (int i = 0; i < m; ++i) {
		int d;
		scanf("%d",&d);
		b = max(b, d);
	}
	int bour = b - a;
	if (bour <= 0)
		printf("%d\n",r);
	else {
		int c = r / a;
		int p = r - a * c;
		p = p + b * c;
		printf("%d\n",p);
	}	 
	return 0;
}

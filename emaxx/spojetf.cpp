#include <bits/stdc++.h>

using namespace std;

int euler(int n)
{	
	int result = n;
	for (int i = 2; i * i <= n ; ++i) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

int main()
{
	int q;
	scanf("%d",&q);
	while (q--) {
		int n;
		scanf("%d",&n);
		printf("%d\n",euler(n));
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

long int euler(long int n)
{	
	long int result = n;
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
	long int n;
	while (scanf("%ld", &n) != EOF && n) {
		if (n == 1)
			printf("0\n");
		else
			printf("%ld\n",euler(n));
	}
	return 0;
}

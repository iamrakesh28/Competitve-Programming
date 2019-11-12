#include <bits/stdc++.h>

using namespace std;

/*int ans[200005];
bool prime[400005];
vector <int> compress;

void sieve()
{
	for (int i = 0;i < 400005; ++i)
		prime[i] = true;
	for (int i = 2; i*i <= 400005; ++i) {
		if (prime[i - 1] == true)
			for (int j = i * i; j <= 400005; ++j) {
				prime[j - 1] = false;
			}
	}
	for (int i = 5;i < 400005; ++i) {
		if (prime[i - 1] == true) 		
			compress.push_back(i);
	}
}
*/

int main()
{
	int n, one = 0, two = 0, d;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&d);	
		if (d == 1)
			one++;
		else
			two++;
	}
	if (one == 0) {
		for (int i = 0; i< n; ++i)
			printf("2 ");
		printf("\n");
	}
	else if (two == 0) {
		for (int i = 0; i< n; ++i)
			printf("1 ");
		printf("\n");
	}
	else {
		printf("2 1 ");
		two--, one--;
		while (two--) 
			printf("2 ");
		while (one--) 
			printf("1 ");
	}
	printf("\n");
	return 0;
}

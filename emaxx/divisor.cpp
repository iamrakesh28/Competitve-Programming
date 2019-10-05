#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int divisor(int num)
{	
	vector <int> power;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			power.push_back(0);
			int ind = power.size() - 1;
			while (num % i == 0) {
				num /= i;
				power[ind]++;
			}
		}
	}
	if (num > 1)
		power.push_back(1);
	int cnt = 1;
	for (auto it : power) {
		cnt *= (it + 1);
	}
	return cnt;
}

int main()
{
	int q;
	scanf("%d",&q);
	while (q--) {
		int a, b;	
		scanf("%d%d",&a,&b);
		printf("%d\n",divisor(gcd(a,b)));
	}
	return 0;
}


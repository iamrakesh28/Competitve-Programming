#include <bits/stdc++.h>

using namespace std;

long int sumPrime[200001];
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

int binary(long int num) 
{
	int begin = 1, end = 200000, mid;
	while (begin < end - 1) {
		int mid = (begin + end) / 2;
		if (sumPrime[mid] == num)
			return mid;
		else if (sumPrime[mid] < num)
			begin = mid;
		else
			end = mid;
	}
	if (sumPrime[begin] < num)
		return end;
	return begin;
}

int gcd(int a, int b) 
{
	if (a == 0)
		return b;
	return gcd(b % a, a);	
}

int main()
{
	sumPrime[0] = 1;
	for (int i = 1; i <= 200000; ++i)
		sumPrime[i] = sumPrime[i-1] + euler(i);
	long int n;
	while (scanf("%ld", &n) != EOF && n) {
		if (n == 1)
			printf("0/1\n");
		else if (n == 2)
			printf("1/1\n");
		else {
			int index = binary(n);
			long int sum = 0, cnt = sumPrime[index - 1];
			for (int i = 1; i <= index; ++i) {
				if (gcd(i,index) == 1) {
					sum++;
				}
				if (sum + cnt == n) {	
					printf("%d/%d\n", i, index);
					break;
				}
			}
		}
	}
	return 0;
}

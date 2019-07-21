#include <bits/stdc++.h>

using namespace std;

long int gcd(long int a, long int b, long int &x, long int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	long int x1,y1;
	long int d = gcd(b%a,a,x1,y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}

int main() {
	long int a,b;
	while (scanf("%ld%ld",&a,&b) != EOF) {
		long int x,y,d;
		d = gcd(a,b,x,y);
		if (a == b) {
			a = min(x,y);
			y = max(x,y);	
			x = a;
		}
		printf("%ld %ld %ld\n",x,y,d);
	}
}

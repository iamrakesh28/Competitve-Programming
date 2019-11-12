#include <iostream>
#include <vector>

using namespace std;

long long x = 32063;
long long factor(long long x) {
	
	vector <long long> f;
	for (long long i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			f.push_back(i);
			while (x % i == 0)
				x = x / i;
		}
	}
	if (x > 1)
		return x;
	return f[f.size() - 1];
}
int main() {

	int q;
	char ver[4];
	scanf("%d", &q);
	while (q--) {
		int rem;
		printf("%d %lld\n", 1, x);
		fflush(stdout);
		scanf("%d", &rem);
		if (rem == 0) {
			printf("%d %lld\n", 2, x);
			fflush(stdout);
			scanf("%s", ver);
			continue;
		}
		long long p = x * x - rem;
		cout<<p<<endl;
		p = factor(p);
		printf("%d %lld\n", 1, p);
		fflush(stdout);
		scanf("%d", &rem);
		if (rem)
			p = rem;
		printf("%d %lld\n", 2, p);
		fflush(stdout);
		scanf("%s", ver);
	}
}

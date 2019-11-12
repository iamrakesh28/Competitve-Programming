#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		long long n, k, sum, rem;
		cin>>n>>k;
		n++;
		if (k % 3) {
			if ((n - 1) % 3 == 0)
				puts("Bob");
			else
				puts("Alice");
		}
		else {
			rem = k / 3;
			sum = (rem - 1) * 3 + 4;
			//cout<<sum<<endl;
			if (sum > n) {
				if ((n - 1) % 3 == 0)
					puts("Bob");
				else
					puts("Alice");
				continue;
			}
			rem = n % sum;
			if (rem == 0)
				puts("Alice");
			else {
				if ((rem - 1) % 3 == 0)
					puts("Bob");
				else
					puts("Alice");

			}
		}
	}
	return 0;
}

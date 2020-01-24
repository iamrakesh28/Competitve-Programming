#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	long long s = 0;
	scanf("%d", &n);
	vector <int> A(n), B(n), C(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &B[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &C[i]);
	for (int i = 0; i < n; ++i)
		A[i] = A[i] ^ B[i];
	for (int i = 0; i < n; ++i) {
		int last, found = 0, d = 0;
		for (int j = 29; j >= 0; --j) {
			if (C[i] & (1 << j)) {
				if ((A[i] & (1 << j)) == 0) {
					found = 1;
					A[i] = A[i] | (1 << j);
					//d = d | (1 << j);
				}
				last = j;
			}
		}
		if (found == 0)
			A[i] = A[i] ^ (1 << last);// d = d | (1 << last);
		//cout<<d<<endl;
		s = s + A[i];
	}
	printf("%ld\n", s);
	return 0;
}

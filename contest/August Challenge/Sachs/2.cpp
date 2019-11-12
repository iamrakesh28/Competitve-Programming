#include <iostream>

using namespace std;

long long nC[200000][105];
int factor(int n, int p) {
	long long ans = 0;
	int val = n;
	if (val % 2 == 0) {
		val = val / 2;
		ans = (ans + 2) % p;
		while (val % 2 == 0)
			val = val / 2;
	}
	for (int i = 3; (long long)i * i <= val; i += 2) {
		if (n % i == 0) {
			ans = (ans + i) % p;
			while (val % i == 0)
				val = val / i;
		}
	}
	if (val > 2)
		ans = (ans + val) % p;
	return ans;
}

int main() {
	cout<<factor(4, 10000)<<endl;
	int p = 100000;
	for (int i = 0; i <= (100002); ++i) {
		for (int j = 0; j <= min(102, i); ++j) {
			if (i == 0 || j == i)
				nC[i][j] = 1;
			//else if (j == 1)
				//nC[i][j] = i;
			else
				nC[i][j] = (nC[i - 1][j - 1] + nC[i - 1][j]) % p;
		}
	}
	cout<<nC[8][1]<<endl;
}

#include <iostream>
#include <cstring>

using namespace std;

const int prime = 1e9 + 7;
char s[5006];
int sub[5006];
long long nc[5006][5006];

int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i <= 5005; ++i) {
		for (int j = 0; j <= 5005; ++j) {
			if (i == 0 || j == 0)
				nc[i][j] = 1;
			else
				nc[i][j] = (nc[i - 1][j - 1] + nc[i - 1][j]) % prime;
		}
	}
	while (t--) {
		int n, q;
		scanf("%d%d%s", &n, &q, s);
	}
	return 0;
}

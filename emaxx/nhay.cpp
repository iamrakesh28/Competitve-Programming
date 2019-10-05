#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int p = 31, m = 1e9 + 9;

int main() {
	int S;
	while (scanf("%d", &S) != EOF) {
		long long hs = 0;
		char c = getchar();
		char *s = new char[S + 1];
		scanf("%[^\n]s", s);
		vector <long long> power, h_t;
		power.push_back(1);
		h_t.push_back(0);
		for (int i = 0; i < S; ++i) {
			power.push_back(p * power[i] % m);
			hs = (hs + (s[i] - 'a' + 1) * power[i]) % m;
		}
		vector <int> occur;
		int i = 0;
		c = getchar();
		while ((c = getchar()) != '\n') {
			if (i > S)
				power.push_back(p * power[i - 1] % m);
			h_t.push_back((h_t[i] + (c - 'a' + 1) * power[i]) % m);
			if (i >= S - 1) {
				long long cur = (h_t[i + 1] - h_t[i - S + 1] + m) % m;
				if (cur == hs * power[i - S + 1] % m)
					occur.push_back(i - S + 1);
			}
			i++;
		}
		for (int i : occur)
			printf("%d\n", i);
		printf("\n");
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int p = 31, m = 1e9 + 7;

vector <int> rabin(string const &s, string const &t) {

	int S = s.size(), T = t.size();
	vector <long long> power(max(S,T));	
	power[0] = 1;
	for (int i = 1; i < max(S, T); ++i)
		power[i] = (power[i - 1] * p) % m;
	vector <long long> h(T + 1, 0);
	for (int i = 0; i < T; ++i)
		h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % m;
	long long h_b = 0;
	for (int i = 0; i < S; ++i)
		h_b = (h_b + (s[i] - 'a' + 1) * power[i]) % m;
	vector <int> occur;
	for (int i = 0; i + S - 1 < T; ++i) {
		long long cur = (h[i + S] + m - h[i]) % m;
		if (cur == h_b * power[i] % m)
			occur.push_back(i);
	}
	return occur;
}
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		string a, b;
		cin>>a>>b;
		vector <int> occur = rabin(b, a);
		if (occur.size()) {
			printf("%d\n", occur.size());
			for (int i : occur)
				printf("%d ", i + 1);
			puts("\n");
		}
		else
			printf("Not Found\n\n");
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, w;
	scanf("%d%d", &n, &w);
	vector <long long> br(n), elp(w), pi(n);
	for (int i = 0; i < n; ++i)
		cin>>br[i];
	for (int i = 0; i < w; ++i)
		cin>>elp[i];
	if (w == 1) {
		printf("%d\n", n);
		return 0;
	}
	pi[0] = 0;
	pi[1] = 1;
	for (int i = 2; i < w; ++i) {
		int j = pi[i - 1];
		while (j > 1 && elp[j] - elp[j - 1] != elp[i] - elp[i - 1])
			j = pi[j - 1];
		if (elp[j] - elp[j - 1] == elp[i] - elp[i - 1])
			j++;
		pi[i] = j;
	}
	int j = 1, ans = 0;
	for (int i = 1; i < n; ++i) {
		if (j == n)
			j = pi[j - 1];
		while (j > 1 && elp[j] - elp[j - 1] != br[i] - br[i - 1])
			j = pi[j - 1];
		if (elp[j] - elp[j - 1] == br[i] - br[i - 1])
			j++;
		if (j == w)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

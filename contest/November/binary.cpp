#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 5;
char s[N], ans[N];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		long long k;
		vector <int> zero;
		scanf("%d%lld", &n, &k);
		char ch = getchar();
		int i = 0;
		while ((ch = getchar()) != '\n') {
			if (ch == '0')
				zero.push_back(i);
			ans[i] = ch;
			s[i++] = ch;
		}
		ans[n] = '\0';
		int p = 0, size = zero.size(), ind;
		for (int i = 0; i < n; ++i) {
			if (size <= p)
				break;
			if (zero[p] - p <= k) {
				ans[i] = '0';
				k = k - (zero[p] - p);
				p++;
				//cout<<zero[p]<<" "<<p<<endl;
			}
			else if (k >= 0) {
				ind = zero[p] - k;
				//cout<<k<<endl;
				k = 0;
				break;
			}
		}
		if (p < size) {
			for (int i = p; i <= zero[p]; ++i)
				ans[i] = '1';
			ans[ind] = '0';
		}
		else {
			for (int i = p; i < n; ++i)
				ans[i] = '1';
		}
		puts(ans);
	}
	return 0;
}

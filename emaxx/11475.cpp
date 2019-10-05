#include <iostream>
#include <cstring>

using namespace std;

char s[200001], r[100001];
int z[200000];

int main() {

	while (scanf("%s", r) != EOF) {
		int n = strlen(r);
		for (int i = 0; i < n; ++i)
			s[i] = r[n - i - 1];
		for (int i = 0; i < n; ++i)
			s[n + i] = r[i];
		memset(z, 0, sizeof(int) * 2 * n);
		int ans = n;
		for (int i = 1, l = 0, r = 0; i < 2 * n; ++i) {
			if (i <= r)
				z[i] = min(r - i + 1, z[i - l]);
			while (i + z[i] < 2 * n && s[z[i]] == s[i + z[i]])
				z[i]++;
			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
			int pos = i - n;
			if (pos >= 0) {
				int len = n - pos;
				//cout<<z[i]<<" "<<pos<<endl;
				if (len <= 2 * z[i])
					ans = min(ans, n - len);
			}
		}
		//cout<<ans<<endl;
		printf("%s", r);
		for (int i = ans - 1; i >= 0; i--)
			putchar(r[i]);
		puts("");
	}
	return 0;
}

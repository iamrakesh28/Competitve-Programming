#include <iostream>
#include <cstring>

using namespace std;

const int p = 31, m = 1e9 + 9;
char s[50005];
long long power[50005], has[50005];

int main() {

	int q, i = 0;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", s);
		int n = strlen(s);
		power[0] = 1;
		for (int i = 0; i < n; ++i)
			power[i + 1] = power[i] * p % m;
		has[0] = 0;
		for (int i = 0; i < n; ++i)
			has[i + 1] = (has[i] + (s[i] - 'A' + 1) * power[i]) % m;
		int l = 0, r = n - 1, cnt = 0, prev = -1;
		while (l <= r) {
			if (l == r) {
				cnt++;
				break;
			}
			long long cur1, cur2;
			cur1 = (has[l + 1] - has[prev + 1] + m) % m;
			cur1 = cur1 * power[n - prev - 2] % m;
			cur2 = (has[n - prev - 1] - has[r] + m) % m;
			cur2 = cur2 * power[n - r - 1] % m;
			if (cur1 == cur2)
				cnt += 2, prev = l;
			else if (l == r - 1)
				cnt++;
			l++;
			r--;
			//cout<<cur1<<" "<<cur2<<" "<<l<<" "<<r<<" "<<prev<<endl;
		}
		printf("Case #%d: %d\n", ++i, cnt);
	}
	return 0;
}

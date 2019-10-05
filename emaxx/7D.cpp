#include <iostream>
#include <cstring>

using namespace std;

const int p = 53, prime = 1e9 + 9;
char s[10000001];
int even[5000000], odd[5000000];
long long power[5000000], hs[5000001];

int main() {

	scanf("%s", s);
	int n = strlen(s);
	power[0] = 1;
	for (int i = 1; i < n; ++i)
		power[i] = power[i - 1] * p % prime;
	hs[0] = 0;
	for (int i = 0; i < n ; ++i)
		hs[i + 1] = (hs[i] + (s[i] - 'a' + 1) * power[i]) % prime;
	long long ans = 0;
	int prev;
	for (int i = 1; i <= n / 2; ++i) {
		long long cur1, cur2;
		cur1 = hs[i] * power[n - 1] % prime;
		cur2 = (hs[2 * i + 1] - hs[i + 1] + prime) % prime;
		cur2 = cur2 * power[n - i - 2] % prime;
		if (cur1 == cur2) {
			if (i & 1) {
				ans += odd[i / 2] + 1;
				odd[i] = odd[i / 2] + 1;
			}
			else {
				ans += even[i / 2 - 1] + 1;
				odd[i] = even[i / 2 - 1] + 1;
			}
		}
		cout<<cur1<<" "<<cur2<<" "<<i<<endl;
		if (i == n / 2)
			continue;
		cur1 = hs[i + 1] * power[n - 1] % prime;
		cur2 = (hs[2 * i + 2] - hs[i + 1]) % prime;
		cur2 = cur2 * power[n - i - 2] % prime;
		if (cur1 == cur2) {
			if (i & 1) {
				ans += odd[i / 2] + 1;
				even[i] = odd[i / 2] + 1;
			}
			else {
				ans += even[i / 2 - 1] + 1;
				even[i] = even[i / 2 - 1] + 1;
			}
		}
		cout<<cur1<<" "<<cur2<<" "<<i<<endl;
		//cout<<odd[i]<<" "<<even[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

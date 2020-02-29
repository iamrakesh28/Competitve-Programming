#include <iostream>

using namespace std;

const int N = 3e5;
long long fact[N];

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i % m;
	long long ans = 0, temp, len;
	len = n;
	temp = len * fact[n - 1] % m;
	temp = len * temp % m;
	ans = temp;
	//cout<<ans<<endl;
	for (int i = 2; i <= n; ++i) {
		len = n - i + 1;
		temp = len * fact[i] % m;
		temp = temp * fact[n - i] % m;
		temp = len * temp % m;
		ans = (ans + temp) % m;
		//cout<<ans<<endl;
	}
	printf("%lld\n", ans);
	return 0;
}

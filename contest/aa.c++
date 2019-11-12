#include <iostream>

using namespace std;

int main() {

	long long n, len = 0;
	cin>>n;
	long long ans = 1;
	for (int i = 2; i <= n; ++i) {
		ans = ans + 4 + 4 * len;
		len++;
	}
	cout<<ans<<endl;
	return 0;
}

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
	cin>>q;
	while (q--) {
		long long n;
		cin>>n;
		if (n == 2) {
			puts("2");
			continue;
		}
		if (n % 2) {
			puts("1");
			continue;
		}
		puts("0");
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
	cin>>q;
	while (q--) {
		long long x, y;
		cin>>x>>y;
		x = x - y;
		if (x > 1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

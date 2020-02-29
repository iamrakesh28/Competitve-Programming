#include <iostream>

using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		long long a, b, r, ans;
		cin>>a>>b;
		ans = a;
		int len = 0;
		r = b;
		while (r) {
			r = r / 10;
			len++;
		}
		r = 0;
		for (int i = 0; i < len; ++i)
			r = r * 10 + 9;
		if (b < r)
			ans = ans * (len - 1);
		else
			ans = ans * len;
		cout<<ans<<endl;
	}
	return 0;
}

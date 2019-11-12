#include <iostream>

using namespace std;

int main() {

	long long n;
	int p;
	scanf("%lld%d", &n, &p);
	int ans = -1;
	for (int i = 1; i < 31; ++i) {
		n = n - p;
		int cnt = 0;
		for (int j = 0; j < 31; ++j)
			if ((1 << j) & n)
				cnt++;
		//cout<<n<<" "<<cnt<<endl;
		if (n < i)
			break;
		if (cnt <= i) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

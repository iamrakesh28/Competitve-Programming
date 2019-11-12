#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	for (int j = 0; j < q; ++j) {
		int s, d;
		long long left = 0, right = 0, temp, ch = 0;
		scanf("%d%d", &d, &s);
		for (int i = 0; i < s; ++i) {
			int c, e;
			scanf("%d%d", &c, &e);
			if (c >= e)
				left += (c - e), ch += c;
			right += e;
		}
		printf("Case #%d: ", j + 1);
		for (int i = 0; i < d; ++i) {
			long long a, b;
			scanf("%ld%ld", &a, &b);
			temp = a + b - right;
			//cout<<temp<<endl;
			if (left >= temp && ch >= a)
				printf("Y");
			else
				printf("N");
		}
		puts("");
	}
	return 0;
}

#include <iostream>

using namespace std;

int main() {
	
	int n, l = 0;
	string s, t;
	scanf("%d", &n);
	cin>>s>>t;
	for (int i = 0; i < n; ++i) {
		bool match = true;
		for (int j = 0; i + j < n; ++j) {
			if (s[i + j] == t[j])
				continue;
			else {
				match = false;
				break;
			}
		}
		if (match) {
			l = n - i;
			break;
		}
	}
	if (l == 0)
		printf("%d\n", n);
	else
		printf("%d\n", n - l);
	return 0;
}

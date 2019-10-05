#include <iostream>
#include <cstring>

using namespace std;

char s[1000001];
int z[1000000], suff[10000001];

int main() {

	scanf("%s", s);
	int n = strlen(s);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
		if (z[i])
			suff[0]++, suff[z[i]]--;
	}
	int k = 0;
	for (int i = 0; i < n; ++i)
		suff[i + 1] += suff[i];
	//for (int i = 0; i < n; ++i)
		//cout<<suff[i]<<" "<<i+1<<endl;
	//cout<<z[n-2]<<endl;
	for (int i = 0; i < n; ++i) {
		//cout<<i+1<<" "<<suff[i]<<endl;
		if (suff[i]) {
			if (z[n - i - 1] != i + 1)
				suff[i] = 0;
			else
				k++;
		}
	}
	k++;
	printf("%d\n", k);
	for (int i = 0; i < n; ++i) {
		if (suff[i])
			printf("%d %d\n", i + 1, suff[i] + 1);
	}
	printf("%d %d\n", n, 1);
	return 0;
}

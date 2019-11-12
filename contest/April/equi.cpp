#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, cnt = 0;
	scanf("%d",&n);
	for (int i = n + 1; i >= 4; i--) {
		for (int j = i - 2; j >= 2; j -= 2) {
			cnt += j * (j - 1) / 2;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

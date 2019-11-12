#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cnt = 0;
	int n = 1000, d = 1;
	for (int i = 0; i < n / 2 && d <= n; ++i) {
		for (int j = 0; j < n; j += (d + 1))
			cnt++;
		//cout<<cnt<<endl;
		for (int j = 1; j < n; j += (d + 1))
			cnt++;
		//cout<<cnt<<endl;
		d *= 2;
	}
	cout<<cnt<<endl;
	return 0;
}

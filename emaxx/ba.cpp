#include <bits/stdc++.h>

using namespace std;

int main() {

	long long d, arr[4];
	//int a = 0b1000;
	//cout<<a<<endl;
	//return 0;
	cin>>arr[0]>>arr[1]>>arr[2]>>d;
	sort(arr, arr + 3);
	long long cnt1 = 0, cnt2 = 0;
	if (arr[1] - arr[0] < d)
		cnt1 = d - (arr[1] - arr[0]);
	if (arr[2] - arr[1] < d)
		cnt2 = d - (arr[2] - arr[1]);
	cout<<cnt1 + cnt2<<endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n;
	long long k;
	cin>>n>>k;
	vector <long long> arr(n);
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	sort(arr.begin(), arr.end());
	int mid = n / 2;
	long long med = arr[mid];
	for (int i = mid + 1; i < n; ++i) {
		if (med == arr[i]) 
			continue;
		long long rem = k - (i - mid) * (arr[i] - med);
		if (rem >= 0) {
			k = rem;
			med = arr[i];
		}
		else {
			rem = k / (i - mid);
			med += rem;
			k = 0;
			break;
		}
	}
	if (k)
		med += k / (n - mid);
	cout<<med<<endl;
	return 0;
}

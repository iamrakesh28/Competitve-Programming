#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 5;
long long arr[N];
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	sort(arr, arr + n);
	long long sum = 0;
	int k = 0;
	vector <long long> v;
	sum += arr[0];
	for (int i = 1; i < n; ++i) {
		if (i % 2 == 0) {
			if (arr[i] >= sum) {
				k++;
				v.push_back(arr[i]);
			}
			else
				sum += arr[i];
		}
		else
			sum += arr[i];
	}
	printf("%d\n", k);
	for (auto it : v)
		cout<<it<<" ";
	puts("");
	return 0;
}

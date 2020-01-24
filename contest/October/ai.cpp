#include <iostream>

using namespace std;

const int N = 1e5;
int arr[N], bi[N];

int main() {

	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		bi[i] = arr[i] / 2;
		sum += bi[i];
	}
	if (sum != 0) {
		for (int i = 0; i < n; ++i) {
			if (arr[i] % 2) {
				if (sum < 0) {
					if (arr[i] > 0) {
						sum++;
						bi[i] += 1;
					}
				}
				else if (sum > 0) {
					if (arr[i] < 0) {
						sum--;
						bi[i] -= 1;
					}
				}
			}
		}
	}
	//cout<<sum<<endl;
	for (int i = 0; i < n; ++i)
		printf("%d\n", bi[i]);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, pos = 0, neg = 0, pmax = -1e9, nmin = 1e9, nminind, pmaxind;
	scanf("%d", &n);
	vector <int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin>>arr[i];
		if (arr[i]  >= 0) {
			pos++;
			if (arr[i] > nmin) {
				pmax = arr[i];
				pmaxind = i;
			}
		}
		else {
			neg++;
			if (arr[i] < nmin) {
				nmin = arr[i];
				nminind = i;
			}
		}
	}
	if (pos % 2 == 0 && neg % 2 == 0) {
		for (int i = 0; i < n; ++i) {
			if (arr[i] >= 0)
				printf("%d ", -arr[i] - 1);
			else
				printf("%d ", arr[i]);
		}
		printf("\n");
		return 0;
	}
	if (pos % 2 == 0 && neg % 2) {
		for (int i = 0; i < n; ++i) {
			if (i == nminind) {
				printf("%d ", -arr[i] - 1);
				continue;
			}
			if (arr[i] >= 0)
				printf("%d ", -arr[i] - 1);
			else
				printf("%d ", arr[i]);
		}
		printf("\n");
		return 0;
	}
	if (pos % 2 && neg % 2 == 0) {
		for (int i = 0; i < n; ++i) {
			if (i == pmaxind) {
				printf("%d ", arr[i]);
				continue;
			}
			if (arr[i] >= 0)
				printf("%d ", -arr[i] - 1);
			else
				printf("%d ", arr[i]);
		}
		printf("\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
			if (arr[i] >= 0)
				printf("%d ", -arr[i] - 1);
			else
				printf("%d ", arr[i]);
		}
		printf("\n");

	return 0;
}

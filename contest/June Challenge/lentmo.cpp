#include <bits/stdc++.h>

#define N 10000
using namespace std;
int arr[N], XOR[N];

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, k;
		int x;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		scanf("%d%d", &k, &x);
		int sum = 0;
		int pos = 0, rem;
		for (int i = 0; i < n; ++i) {
			int xo = (arr[i] ^ x) - arr[i];
			if (xo > 0)
				pos++;
			XOR[i] = xo;
			sum += arr[i];
			//cout<<xo<<" ";
		}
		//cout<<endl;
		if (x == 0) {
			printf("%d\n", sum);
			continue;
		}
		sort(XOR, XOR + n);
		reverse(XOR, XOR + n);
		arr[0] = XOR[0];
		for (int i = 1; i < n; ++i)
			arr[i] = arr[i - 1] + XOR[i];
		if (k == n)
			sum = sum + max((int)0, arr[n - 1]);
		else if (pos % k == 0) {
			if (pos)
				sum = sum + arr[pos - 1];
		}
		else if (k < pos) {
			rem = pos % k;
			if (rem % 2) {
				if ((rem + k) % 2 == 0) {
					rem = (rem + k) / 2;
					if (n - pos >= k - rem) {
						sum = sum + arr[pos - 1];
						printf("%d\n", sum);
						continue;
					}
				}
				if (pos == n)
					sum = sum + arr[pos - 2];
				else
					sum = sum + max(arr[pos - 2], arr[pos]);
			}
			else
				sum = sum + arr[pos - 1];
		}
		else {
			rem = k - n + pos;
			if (pos == 1)
					sum = sum + max((int)0, arr[k - 1]);
			else if (rem > pos / 2) {
				rem = 2 * rem - pos;
				sum = sum + max(arr[k - 1], arr[pos - rem - 1]);
			}
			else {
				if (pos % 2)
					sum = sum + max(arr[pos], arr[pos - 2]);
				else
					sum = sum + arr[pos - 1];
			}
			
		}
		assert(sum >= 0);
		printf("%d\n", sum);
	}
	return 0;
}

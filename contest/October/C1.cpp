#include <iostream>
#include <set>

using namespace std;

const int N = 1e5;
int arrx[N], arry[N], arrz[N];
bool rem[N];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		arrx[i] = x;
		arry[i] = y;
		arrz[i] = z;
		rem[i] = false;
	}
	int x, y, z, start, second, ind, a, b, c;
	for (int i = 0; i < n; ++i) {
		if (rem[i])
			continue;
		start = i;
		ind = -1;
		for (int j = i + 1; j < n; ++j) {
			if (rem[j])
				continue;
			x = abs(arrx[i] - arrx[j]);
			y = abs(arry[i] - arry[j]);
			z = abs(arrz[i] - arrz[j]);
			if (ind == -1) {
				a = x, b = y, c = z;
				ind = j;
				continue;
			}
			if (x <= a && y <= b && z <= c) {
				a = x, b = y, c = z;
				ind = j;
			}
		}
		rem[start] = rem[ind] = true;
		printf("%d %d\n", start + 1, ind + 1);
	}
	return 0;
}

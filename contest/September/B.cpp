#include <iostream>

using namespace std;

const int N = 1e3 + 5;
long long mat[N][N], arr[N];

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {

	int n;
	long long mn = 2e10, ind;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long long g = 0;
		for (int j = 0; j < n; ++j) {
			cin>>mat[i][j];
			g = gcd(g, mat[i][j]);
		}
		if (g < mn) {
			mn = g;
			ind = i;
		}
			//cout<<g<<endl;
		arr[i] = g;
	}
	for (int i = 0; i < n; ++i) {
		if (i == ind) {
			arr[i] = mn;
			continue;
		}
		arr[i] = mat[ind][i] / mn;
	}
	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";
	puts("");
	return 0;
}

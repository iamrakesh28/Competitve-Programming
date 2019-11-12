#include <iostream>

using namespace std;

int main() {

	double h, l, ans;
	cin>>h>>l;
	ans = (l * l - h * h) / (2 * h);
	printf("%0.9lf\n", ans);
	return 0;
}

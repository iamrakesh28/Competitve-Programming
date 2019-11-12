#include <iostream>

using namespace std;

int sum(int a, int b) {
	return a + b;
}
int main() {

	int (*a)(int, int) = &sum;
	cout<<sum(2, 3)<<endl<<(*a)(2, 3)<<endl;
	return 0;
}

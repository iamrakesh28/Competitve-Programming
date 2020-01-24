#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1000;
bool num[N];

void recur(int i, int sum) {
	if (i <= 0) {
		//int sq = sqrt(sum);
		//if (sq * sq == sum)
		num[sum] = true;
		return;
	}
	for (int j = 1; j <= 9; ++j)
		recur(i - 1, sum + j * j);
	return ;
}

int main() {
	memset(num, false, sizeof num);
	recur(7, 0);
	for (int i = 0; i < N / 3; ++i)
		if (!num[i])
			printf("%d\n", i);
	return 0;
}

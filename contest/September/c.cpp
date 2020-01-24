#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

char s[N], t[N];

int main() {

	int n, a = 0, b = 0;
	vector <int> A, B;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c", s + i);
		if (s[i] == 'a')
			a++;
		else
			b++;
	}
	for (int i = 0; i < n; ++i) {
		scanf(" %c", t + i);
		if (t[i] == 'a')
			a++;
		else
			b++;
		if (s[i] != t[i]) {
			if (s[i] == 'a')
				A.push_back(i);
			else
				B.push_back(i);
		}
	}
	if (a % 2 || b % 2) {
		printf("-1\n");
		return 0;
	}
	if ((A.size() + B.size()) % 2) {
		printf("-1\n");
		return 0;
	}
	if (A.size() % 2)
		printf("%d\n", (A.size() + B.size()) / 2 + 1);
	else
		printf("%d\n", (A.size() + B.size()) / 2);
	for (int i = 1; i < A.size(); i += 2)
		printf("%d %d\n", A[i] + 1, A[i - 1] + 1);
	for (int i = 1; i < B.size(); i += 2)
		printf("%d %d\n", B[i] + 1, B[i - 1] + 1);
	int l = A.size() - 1, r = B.size() - 1;
	if (A.size() % 2)
		printf("%d %d\n%d %d\n", A[l] + 1, A[l] + 1, A[l] + 1, B[r] + 1);
	return 0;
}

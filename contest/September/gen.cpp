#include <iostream>

using namespace std;

const int N = 1e5;

int main() {

	//FILE *fp = fopen("test", "w");
	char c = 'a';
	for (int i = 0; i < N; ++i) {
		c = 'a' + (c - 'a' + 1) % 26;
		//fprintf(fp, "%c", c);
		fprintf(stdout, "%c", c);
	}
	fprintf(stdout, "\n%d\n", N);
	//fprintf(fp, "\n%d\n", N);
	int q = N, dir = 0;
	int l = 1, r = q;
	while (q--) {
		fprintf(stdout, "%d %d %d\n", 2, l, r);
		//fprintf(fp, "%d %d %d\n", 2, l, r);
		l++;
	}
	//fclose(fp);
	return 0;
}

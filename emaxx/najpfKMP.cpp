#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector <int> kmp(int n, string const &t) {

	int T = (int)t.length();	
	vector <int> occur, pi(T, 0);
	for (int i = 1; i < T; ++i) {
		int j = pi[i - 1];
		while (j > 0 && t[j] != t[i])
			j = pi[j - 1];
		if (t[i] == t[j])
			j++;
		pi[i] = j;
		//cout<<j<<"\t";
		if (j == n)
			occur.push_back(i - 2 * n);
	}
	return occur;
}
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		string a, b;
		cin>>a>>b;
		//b = b + "\";
		vector <int> occur = kmp(b.length(), b + "!" + a);
		if (occur.size()) {
			printf("%d\n", occur.size());
			for (int i : occur)
				printf("%d ", i + 1);
			puts("\n");
		}
		else
			printf("Not Found\n\n");
	}
	return 0;
}

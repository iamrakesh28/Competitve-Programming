#include <iostream>

using namespace std;

int main() {

	int n, lsum = 0, rsum = 0, l = 0, r = 0, win = 0;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		if (i < n / 2) {
			if (c == '?')
				l++;
			else
				lsum = lsum + (c - '0');
		}
		else {
			if (c == '?')
				r++;
			else
				rsum = rsum + (c - '0');
		}
		//cout<<c<<endl;
	}
	//cout<<lsum<<" "<<rsum<<endl;
	if (lsum == rsum) {
		if (l == r)
			puts("Bicarp");
		else
			puts("Monocarp");
		return 0;
	} 
	if (l + r == 0) {
		if (lsum == rsum)
			puts("Bicarp");
		else
			puts("Monocarp");
		return 0;
	}
	if (l < r) {
		r = r - l;
		if (lsum < rsum) {
			puts("Monocarp");
			return 0;
		}
		else {
			int diff = lsum - rsum;
			if (diff <= ((r / 2) * 9))
				puts("Bicarp");
			else
				puts("Monocarp");
		}
	}
	else {
		l = l - r;
		if (lsum > rsum) {
			puts("Monocarp");
			return 0;
		}
		else {
			int diff = rsum - lsum;
			if (diff <= ((l / 2) * 9))
				puts("Bicarp");
			else
				puts("Monocarp");
		}
	}
	return 0;
}

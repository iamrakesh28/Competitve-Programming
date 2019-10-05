#include <bits/stdc++.h>

using namespace std;

long int ri[1000000], ci[1000000];
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		long long r, c, sum1 = 0, sum2 = 0, mr = -1, mc = -1, mri, mci, a, b;
		cin>>r>>c;
		mri = r;
		mci = c;
		for (int i = 0; i < r; ++i) {
			cin>>a;
			ri[i] = a;
			sum1 += a;
			mr = max(mr, a);
			if (!a)
				mri--;
		}
		for (int i = 0; i < c; ++i) {
			cin>>b;	
			ci[i] = b;	
			sum2 += b;
			mc = max(mc, b);
			if (!b)
				mci--;
		}
		bool win = true;
		if (r * c <= 100000) {
			for (int i = 0; i < r; ++i) {
				int req = ri[i];
				for (int j = 0; j < c; ++j) {
					if (req == 0)
						break;
					if (ci[j])
						ci[j]--, req--;
				}
				if (req) {
					win = false;
					break;
				}
			}
			if(win)
				printf("YES\n");
			else
				printf("NO\n");
			continue;
		}
		if (mr > mci || mc > mri)
			win = false;
		if (sum1 != sum2)
			win = false;
		if(win)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

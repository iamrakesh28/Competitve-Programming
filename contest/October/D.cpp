#include <iostream>
#include <set>

using namespace std;
const int N = 3e5 + 5;

char s[N];

int main() {

	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	int n;
	char ch;
	cin>>n;
	ch = getchar();
	set <int> A, B;
	for (int i = 0; i < n; ++i) {
		ch = getchar();
		s[i] = ch;
		if (ch == 'A')
			A.insert(i);
		else
			B.insert(i);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') {
			if (i + 1 < n) {	
				if (s[i + 1] == 'A') {
					ans += n - i - 1;
					auto it = B.lower_bound(i);
					if (it != B.end())
						ans--;
				}
				else {
					auto it = A.lower_bound(i + 1);
					if (it != A.end()) {
						ans += n - *it;
					}
				}
			}
		}
		else {
			if (i + 1 < n) {	
				if (s[i + 1] == 'B') {
					ans += n - i - 1;
					auto it = A.lower_bound(i);
					if (it != A.end())
						ans--;
				}
				else {
					auto it = B.lower_bound(i + 1);
					if (it != B.end()) {
						ans += n - *it;
					}
				}
			}
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<"\n";
	return 0;
}

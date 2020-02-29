#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
int ans[N];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, val, cit;
		scanf("%d", &n);
		multiset <int> s;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &val);
			s.insert(val);
			cit = s.size();
			//cout<<cit<<" "<<*s.begin()<<" : ";
			while (*s.begin() < cit) {
				//cout<<*s.begin()<<endl;
				s.erase(s.begin());
				cit--;
			}
			ans[j] = s.size();
			//cout<<s.size()<<" "<<*s.begin()<<endl;
		}
		printf("Case #%d:", i + 1);
		for (int j = 0; j < n; ++j)
			printf(" %d", ans[j]);
		puts("");
	}
	return 0;
}

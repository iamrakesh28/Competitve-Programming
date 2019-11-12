#include <iostream>
#include <set>
#include <iterator> 

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	long long v, a = 0, b, s;
	multiset <long long> q;
	for (int i = 0; i < n; ++i) {
		cin>>v;
		if (q.find(v) != q.end()) {
			q.erase(q.find(v));
			a -= v;
		}
		else {
			q.insert(v);
			a += v;
		}
	}
	if (a & 1) {
		puts("NO");
		return 0;
	}
	while (q.size() >= 2) {
		auto it = q.end();
		it--;
		a = *it;
		q.erase(it);
		it = q.end();
		it--;
		b = *it;
		//cout<<b<<endl;
		q.erase(it);
		if (a - b > 0)
			q.insert(a - b);
	}
	if (q.size())
		puts("NO");
	else
		puts("YES");
	return 0;
}

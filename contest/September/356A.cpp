#include <iostream>
#include <set>

using namespace std;

const int N = 3e5;
int win[N];

void solve(set <int> & s, int l, int r, int x) {
	set <int> :: iterator cur, next;
	int temp;
	cur = s.find(l);
	if (l == x)
		win[l - 1] = 0;
	else
		win[l - 1] = x;
	next = cur;
	next++;
	temp = *next;
	if (l != x)
		s.erase(cur);
	l = temp;
	cur = s.find(l);
	while (cur != s.end() && *cur <= r) {
		if (l == x)
			win[l - 1] = 0;
		else
			win[l - 1] = x;
		next = cur;
		next++;
		if (next == s.end()) {
			if (l != x)
				s.erase(cur);
			break;
		}
		temp = *next;
		if (l != x)
			s.erase(cur);
		l = temp;
		cur = s.find(l);
	}
	return;
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	set <int> s;
	for (int i = 1; i <= n; ++i)
		s.insert(i);
	for (int i = 0; i < m; ++i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		set <int> :: iterator next, cur = s.find(l);
		if (cur != s.end())
			solve(s, l, r, x);
		else {
			s.insert(l);
			cur = s.find(l);
			next = cur;
			next++;
			l = *next;
			s.erase(cur);
			solve(s, l, r, x);
		}
		//for (auto it : s)
		//	cout<<it<<" ";
		puts("");
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", win[i]);
	puts("");
	return 0;
}

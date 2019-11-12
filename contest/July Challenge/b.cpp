#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	char suzuka[12];
	scanf("%[^\n]s", suzuka);
	int  ans, cnt = 0;
	int ch[] = {1, 4, 7}, num;
	vector <int> s, p, m;
	for (int i = 0; i < 3; ++i) {
		num = suzuka[ch[i] - 1] - '0';
		if (suzuka[ch[i]] == 's')
			s.push_back(num);
		else if (suzuka[ch[i]] == 'p')
			p.push_back(num);
		else
			m.push_back(num);
	}
	//cout<<s.size()<<" "<<p.size()<<" "<<m.size()<<endl;
	if (s.size() == 1 && p.size() == 1 && m.size() == 1)
		ans = 2;
	else {
		if (s.size() == 2) {
			int ab = abs(s[0] - s[1]);
			if (ab == 1 || ab == 0 || ab == 2)
				ans = 1;
			else
				ans = 2;
		}
		else if (p.size() == 2) {
			int ab = abs(p[0] - p[1]);
			if (ab == 1 || ab == 0 || ab == 2)
				ans = 1;
			else
				ans = 2;
		}
		else if (m.size() == 2) {
			int ab = abs(m[0] - m[1]);
			if (ab == 1 || ab == 0 || ab == 2)
				ans = 1;
			else
				ans = 2;
		}
		else if (s.size() == 3) {
			sort(s.begin(), s.end());
			set <int> S;
			for (auto x : s)
				S.insert(x);
			if (S.size() == 1)
				ans = 0;
			else if (S.size() == 2)
				ans = 1;
			else {
				if (s[0] == s[1] - 1 && s[1] == s[2] - 1)
					ans = 0;
				else {
					if (abs(s[0] - s[1]) <= 2)
					cnt++;
					if (abs(s[1] - s[2]) <= 2)
					cnt++;
					if (cnt)
						ans = 1;
					else
						ans = 0;
				}
			}
		}
		else if (p.size() == 3) {
			sort(p.begin(), p.end());
			set <int> S;
			for (auto x : p)
				S.insert(x);
			if (S.size() == 1)
				ans = 0;
			else if (S.size() == 2)
				ans = 1;
			else {
				if (p[0] == p[1] - 1 && p[1] == p[2] - 1)
					ans = 0;
				else {
					if (abs(p[0] - p[1]) <= 2)
					cnt++;
					if (abs(p[1] - p[2]) <= 2)
					cnt++;
					if (cnt)
						ans = 1;
					else
						ans = 0;
				}
			}		
		}
		else if (m.size() == 3) {
			sort(m.begin(), m.end());
			set <int> S;
			for (auto x : m)
				S.insert(x);
			if (S.size() == 1)
				ans = 0;
			else if (S.size() == 2)
				ans = 1;
			else {
				if (m[0] == m[1] - 1 && m[1] == m[2] - 1)
					ans = 0;
				else {
					if (abs(m[0] - m[1]) <= 2)
					cnt++;
					if (abs(m[1] - m[2]) <= 2)
					cnt++;
					if (cnt)
						ans = 1;
					else
						ans = 0;
				}
			}		
		}
	}
	printf("%d\n", ans);
	return 0;
}

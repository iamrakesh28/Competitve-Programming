#include <bits/stdc++.h>

using namespace std;

char E[305];
vector <char> postfix;

bool oper(char c) {
	switch(c) {
		case '|' :
		case '&' :
		case '^' : return true;
	}
	return false;
}
void con() {
	stack <char> q;
	for (char *p = E; *p != '\0'; ++p) {
		if (*p == '(')
			q.push(*p);
		else if (*p == ')') {
			while (q.top() != '(') {
				postfix.push_back(q.top());
				q.pop();
			}
			q.pop();
		}
		else if (oper(*p))
			q.push(*p);
		else
			postfix.push_back(*p);
	}
}

char eval(char a, char b, char op) {
	if (op == '|') {
		if (a == '1' || b == '1')
			return '1';
		if (a == '0')
			return b;
		if (b == '0')
			return a;
		if (a == b)
			return a;
		return '1';
	}
	else if (op == '&') {
		if (a == '0' || b == '0')
			return '0';
		if (a == '1')
			return b;
		if (b == '1')
			return a;
		if (a == b)
			return a;
		return '0';
	}
	else {
		if (a == '0')
			return b;
		if (b == '0')
			return a;
		if (a == '1' && b == '1')
			return '0';
		if (b == '1') {
			if (a == 'x')
				return 'X';
			else
				return 'x';
		}
		if (a == '1') {
			if (b == 'x')
				return 'X';
			else
				return 'x';
		}
		if (a == b)
			return '0';
		return '1';
	}
}
int solve() {
	if (postfix.size() == 1) {
		if (postfix[0] == '0' || postfix[0] == '1')
			return 0;
		return 1;
	}
	stack <char> q;
	for (int i = 0; i < postfix.size(); ++i) {
		if (oper(postfix[i])) {
			char a = q.top();
			q.pop();
			char b = q.top();
			q.pop();
			char c = eval(a, b, postfix[i]);
			q.push(c);
		}
		else
			q.push(postfix[i]);
	}
	char a = q.top();
	q.pop();
	//cout<<a<<endl;
	if (a == '0' || a == '1')
		return 0;
	return 1;
}
int main() {

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%s", E);
		postfix.clear();
		con();
		printf("Case #%d: %d\n", i + 1, solve());
		/*for (auto it : postfix)
			cout<<it;
		cout<<endl;*/
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
struct Node {
	int a, b;
	Node *l, *r;
};

void solve(int i, Node *left, Node *right)
{
	if (i > n)
		return;
	if (left->b + right->b > i)
		solve(i + 1, left, right);
	else {
		Node *node = new Node;
		node->a = left->a + right->a;
		node->b = left->b + right->b;
		left->r = node;
		right->l = node;
		node->l = left;
		node->r = right;
		solve(i + 1, left, node);
		solve(i + 1, node, right);
	}
}

int main()
{
	int k;
	scanf("%d%d",&n, &k);
	Node *start = new Node;
	Node *end = new Node;
	start->a = 0;
	start->b = 1;
	start->l = NULL;
	start->r = end;
	end->a = 1;
	end->b = 2;
	end->l = start;
	end->r = NULL;
	solve(1, start, end); 
	Node *t = start;
	for (int i = 2; i <= k; ++i) {
		t = t->r;
	}
	printf("%d/%d\n",t->a, t->b);
	return 0;
}

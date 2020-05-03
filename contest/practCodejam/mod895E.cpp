#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <time.h>
#include <algorithm>

using namespace std;

int n, q;
double a[1000000];
double add[1000000];
double mult[1000000];
double t[1000000];

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = a[tl];
		mult[v] = 1;
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = t[v * 2] + t[v * 2 + 1];
	mult[v] = 1;
}

void push(int v, int tl, int tr)
{
	t[v * 2] *= mult[v];
	t[v * 2 + 1] *= mult[v];
	mult[v * 2] *= mult[v];
	mult[v * 2 + 1] *= mult[v];
	add[v * 2] *= mult[v];
	add[v * 2 + 1] *= mult[v];
	mult[v] = 1;
	int tm = (tl + tr) / 2;
	t[v * 2] += (double)(tm - tl + 1)*add[v];
	t[v * 2 + 1] += (double)(tr - tm)*add[v];
	add[v * 2] += add[v];
	add[v * 2 + 1] += add[v];
	add[v] = 0;
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void update(int v, int tl, int tr, int l, int r, double mult_val, double add_val)
{
	if (l > r)
		return;
	if (tl == l&&tr == r)
	{
		t[v] *= mult_val;
		t[v] += double(tr - tl + 1)*add_val;
		mult[v] *= mult_val;
		add[v] *= mult_val;
		add[v] += add_val;
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	update(v * 2, tl, tm, l, min(tm, r), mult_val, add_val);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, mult_val, add_val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

double get(int v, int tl, int tr, int l, int r)
{
	if (tl == l&&tr == r)
		return t[v];
	if (l > r)
		return 0;
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n - 1);
	while (q--)
	{
		int type, l, r;
		cin >> type >> l >> r;
		l--;
		r--;
		if (type == 1)
		{
			int le, ri;
			cin >> le >> ri;
			le--;
			ri--;
			double avg_val1 = get(1, 0, n - 1, l, r) / double(r - l + 1);
			double avg_val2 = get(1, 0, n - 1, le, ri) / double(ri - le + 1);
			update(1, 0, n - 1, l, r, double(r - l) / double(r - l + 1), avg_val2 / double(r - l + 1));
			update(1, 0, n - 1, le, ri, double(ri - le) / double(ri - le + 1), avg_val1 / double(ri - le + 1));
		}
		else
			printf("%.7f\n", get(1, 0, n - 1, l, r));
	}
}

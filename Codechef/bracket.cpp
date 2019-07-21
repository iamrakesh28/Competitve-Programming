#include <bits/stdc++.h>

using namespace std;

int calculate(int *pos,char *brac,int size)
{
	int left=0,right=0,swap=0;
	if(size == 0)
	return 0;
	if(brac[0] == ')')
	left++;
	else
	right++;
	int *count = new int [size];
	count[0] = 0;
	for(int i=1;i < size;++i)
	{
		if(brac[i] == ')')
		left++;
		else
		right++;
		count[i] = count[i-1];
		if(pos[i] > pos[i-1] + 1)
		count[i]++;
	}
	//printf("%d %d %d\n",left,right,size);
	if(left == 0 || right == 0)
	{
		if(left)
		swap += /*count[left/2 - 1]*/ + 1;
		else
		swap += /*count[size-1] - count[right/2]*/ + 1;
		return swap;
	}
	//calculate
	int test;
	if(left > right)
	{
		test = left - right;
		swap += /*count[test/2 - 1]*/ + 1;
		swap += /*count[size-1] - count[test]*/ + 1;
	}
	else if(left == right)
	{
		swap += /*count[size-1]*/ + 2;
	}
	else 
	{
		test = right - left;
		swap += /*count[size-1] - count[size-test/2 - 1]*/ + 1;
		swap += /*count[size - test -1]*/ + 1;
	}
	return swap;
}

int main()
{
	int n,val=0;
	scanf("%d",&n);
	//fflush(stdin);
	char ch = getchar();
	ch = getchar();
	int *pos = new int [n];
	char *brac = new char [n+1];
	pos[val] = 0;
	brac[val] = ch;
	val++;
	for(int i=1;i<n;++i)
	{
		ch = getchar();
		if(ch == ')' && val > 0 && brac[val-1] == '(')
		{	
			val--;
			continue;
		}
		brac[val] = ch;
		pos[val] = i;;
		val++;
	}
	int count = calculate(pos,brac,val);
	printf("%d\n",count);
	return 0;
}

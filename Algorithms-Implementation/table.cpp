#include <bits/stdc++.h>

#define SIZE 100001
using namespace std;

int min(int a,int b)
{
	return (a < b ? a : b);
}

int max(int a,int b)
{
	return (a > b ? a : b);
}
int solve(char *M,char *N,int row,int col)
{
	int steps;
	steps = max(2*(min(row,col) - 2),0) + 1	;
	if(row == 1 || col == 1)
	steps = 0;	
	if(row == col)
	{
		if(row == 1)
		{
			if(M[0] == '1' && N[0] == '1')
			return 0;
			return 1;
		}
		if(M[row - max(col-1,0) - 1] == '0' && N[row - max(col-1,0) - 1] == '0')
		return 0;
		if(M[0] == '1' && N[0] == '1')
		return 0;
		return 1;
	}
	if(steps%2 == 0)
	{
		if(row < col)
		{
			if(M[col - max(row-2,0) - 1] == '1' && M[col - max(row-2,0) - 2] == '0')
			return 0;
		}
		else
		{
			if(N[row - max(col-2,0) - 1] == '1' && N[row - max(col-2,0) - 2] == '0')
			return 0;
		}
	}
	else
	{
		if(row < col)
		{
			if(M[col - max(row-2,0) - 1] == '0' && M[col - max(row-2,0) - 2] == '1')
			return 0;
		}
		else
		{
			if(N[row - max(col-2,0) - 1] == '0' && N[row - max(col-2,0) - 2] == '1')
			return 0;
		}
	}
	return 1;
}
int Solve(char *M,char *N,int row,int col)
{
	int cur,left,up;
	cur = solve(M,N,row,col);
	if(cur == 0)
	return 0;
	if(row - 1 > 0)	
	{
		up = solve(M,N,row-1,col);
		if(up == 0)
		return 1;
	}
	else
	up = M[col-1] - '0';
	if(col-1 > 0)
	{
		left = solve(M,N,row,col-1);
		if(left == 0)
		return 1;
	}
	else
	left = N[row-1] - '0';
	if(up == 1 && left == 1)
	return 0;
	return 1;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char M[SIZE],N[SIZE];
		scanf("%s%s",M,N);
		int t;
		scanf("%d",&t);
		while(t--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d",Solve(M,N,x,y));	
		}
	}
	putchar('\n');
	return 0;
}

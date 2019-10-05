#include <bits/stdc++.h>

using namespace std;

typedef vector <string> vs;
int maxm;
bool isPossible(int n,int row,int col, vs &chess)
{
	//row check
	for(int i=col;i<n;++i)
	{
		if(chess[row][i] == 'R')
		return false;
		if(chess[row][i] == 'X')
		break;
	}
	for(int i=col;i>=0;--i)
	{
		if(chess[row][i] == 'R')
		return false;
		if(chess[row][i] == 'X')
		break;
	}
	//col check
	for(int i=row;i<n;++i)
	{
		if(chess[i][col] == 'R')
		return false;
		if(chess[i][col] == 'X')
		break;
	}
	for(int i=row;i>=0;--i)
	{
		if(chess[i][col] == 'R')
		return false;
		if(chess[i][col] == 'X')
		break;
	}
	return true;
}
void backtrack(int n, vs &chess,int count,int row,int col)
{
	maxm = max(maxm,count);
	for(int j=col;j<n;++j)
	{
		if(chess[row][j] == '.')
		{
		 	bool res = isPossible(n,row,j,chess);
			if(res == true)
			{
				count++;
				chess[row][j] = 'R';
				backtrack(n,chess,count,row,j+1);
				chess[row][j] = '.';
				count--;
			}
			backtrack(n,chess,count,row,j+1);
		}
	}
	for(int i=row+1;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(chess[i][j] == '.')
			{
			 	bool res = isPossible(n,i,j,chess);
				if(res == true)
				{
					count++;
					chess[i][j] = 'R';
					backtrack(n,chess,count,i,j+1);
					chess[i][j] = '.';
					count--;
				}
				backtrack(n,chess,count,i,j+1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n && n)
	{
		maxm = 0;
		vs chess(n);
		for(int i=0;i<n;++i)
		cin>>chess[i];
		backtrack(n, chess,0,0,0);
		cout<<maxm<<endl;
	}
	return 0;
}

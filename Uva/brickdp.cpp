#include <bits/stdc++.h>

#define PRIME 1000000007

using namespace std;

struct brick{
	long int up,down;
};

long int solve(long int n,int k)
{
	//down as 1-D version
	long int ways = 0;
	brick **Brick = new brick*[n];
	for(int i=0;i<n;++i)
	{
		Brick[i] = new brick[k];
		for(int j=0;j<k;++j)
		Brick[i][j].up = Brick[i][j].down = 0;
	}
	for(int i=0;i<n;++i)
	Brick[i][0].down = 1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<k;++j)
		{
			//include
			if(i >=2 && j >= 1)
			Brick[i][j].down = (Brick[i][j].down + Brick[i-2][j-1].down)%PRIME; 
			//doesn't include 
			if(i >= 1)
			Brick[i][j].down = (Brick[i][j].down + Brick[i-1][j].down)%PRIME; 
			//cout<<Brick[i][j].down<<" ";
		}
		//cout<<endl;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<k;++j)
		{
			//include
			Brick[i][j].up = (Brick[i][j].up + 2*Brick[i][j].down)%PRIME; 
			//cout<<Brick[i][j].down<<" ";
			if(i >=1 && j >= 1)
			Brick[i][j].up = (Brick[i][j].up + 2*Brick[i-1][j-1].down)%PRIME; 
			//doesn't include  
			if(i >= 1)
			Brick[i][j].up = (Brick[i][j].up + Brick[i-1][j].down)%PRIME; 
			cout<<Brick[i][j].up<<" ";
		}
		cout<<endl;
	}
	return Brick[n-1][k-1].up;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{	
		long int n;
		int k;
		scanf("%ld%d",&n,&k);
		cout<<solve(n,k)<<endl;
	}
	return 0;
}

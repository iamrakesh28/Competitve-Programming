#include <bits/stdc++.h>

using namespace std;

unsigned int solve(unsigned int x,unsigned int l, unsigned int r)
{
	unsigned int maxm=0,y=0;
	for(int i=8*sizeof(unsigned int)-1;i>=0;i--)
	{
		unsigned int a = y | (1<<i);
		if((1 << i)&x)
		{
			maxm = maxm | (1 << i);
		}
		else if(a <= r)
		{
			maxm = maxm | (1 << i);
			y = y | (1 << i);
			//cout<<maxm<<endl;
		}
		//cout<<y<<endl;
	}
	while(y<l)
	y++;
	maxm = x^y;
	return maxm;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		unsigned int l,r,x;
		scanf("%u%u%u",&x,&l,&r);
		cout<<solve(x,l,r)<<endl;
	}
	
	return 0;
}

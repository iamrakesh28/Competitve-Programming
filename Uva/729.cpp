#include <bits/stdc++.h>

using namespace std;

void hamming(int mask,int n,int h,int pos,int hamm)
{
	if(hamm > h)
	return;
	if(pos == n)
	{
		if(hamm == h)
		{
			for(int i=0;i<n;++i)
			if((mask >> i)%2)
			putchar('1');
			else
			putchar('0');	
			putchar('\n');	
		}
		return ;
	}
	hamming(mask,n,h,pos+1,hamm);
	hamming(mask | (1 << pos),n,h,pos+1,hamm+1);
} 
int main()
{
	int q,i=0;
	scanf("%d",&q);
	while(q--)
	{
		int n,h;
		scanf("%d%d",&n,&h);
		if(i++)
		putchar('\n');
		hamming(0,n,h,0,0);
	}
	return 0;
}

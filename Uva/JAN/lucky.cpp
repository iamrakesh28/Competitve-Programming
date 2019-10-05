#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,a,b,common=0,ca=0,cb=0;
		scanf("%d%d%d",&n,&a,&b);
		int *seq = new int[n];
		for(int i=0;i<n;++i)
		{
			scanf("%d",seq+i);
			if(seq[i] % (a*b) == 0)
			common++;
			else if(seq[i] % a == 0)
			ca++;
			else if(seq[i] % b == 0)
			cb++;
		}
		if(common)
		{
			if(ca >= cb)
			printf("BOB\n");
			else 
			printf("ALICE\n");
		}
		else
		{
			if(ca > cb)
			printf("BOB\n");
			else
			printf("ALICE\n");
		}
		delete [] seq;
	}
	return 0;
}

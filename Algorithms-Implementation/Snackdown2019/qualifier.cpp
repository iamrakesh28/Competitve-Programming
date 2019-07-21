#include <bits/stdc++.h>

using namespace std;

bool compare(long int &a,long int &b)
{
	return a > b;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,k,count=0;
		scanf("%d%d",&n,&k);
		long int *score = new long int[n];
		for(int i=0;i<n;++i)
		scanf("%ld",score+i);
		sort(score,score+n,compare);
		for(int i=k;i<n;++i)
		{
			if(score[i] == score[k-1])
			count++;
			else
			break;
		}
		printf("%d\n",k+count);
		delete [] score;
	}
	return 0;
}

#include <bits/stdc++.h>

#define size 1000
using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char string[2*size];
		long int num=0,n;
		int i=0,count,a=0,b=0,diff;
		vector <int> seq;
		int *prefix_neg = (int *)calloc(size,sizeof(int));
		int *prefix_pos = (int *)calloc(size,sizeof(int));
		scanf("%s%ld",string,&n);
		while(string[i]!='\0')
		{
			if(string[i]=='a')
			{
				a++;
			}
			else
			{
				b++; 
			}
			if(a>b)
			num++;
			seq.push_back(a-b);
			i++;
		}
		count  = i;
		diff = a-b;
		sort(seq.begin(),seq.end());
		for(i=0;i<count;++i)
		{
			if(seq[i]>=0)
			{
				prefix_pos[seq[i]]++;
			}
			else
			{
				prefix_neg[(-1)*seq[i]-1]++;
			}
		}
		for(i=size-1;i>0;--i)
		{
			prefix_pos[i-1] += prefix_pos[i];
		}
		prefix_neg[0] += prefix_pos[0];
		for(i=0;i<size-1;++i)
		{
			prefix_neg[i+1] += prefix_neg[i];
		}
		if(diff>=0)
		{
			for(i=0;i<n-1;++i)
			{
				if(diff==0)
				{
					num += prefix_pos[1];
				}
				else if(diff<2)
				{
					num += prefix_pos[0];
				}
				else
				num += prefix_neg[diff-2];
				diff += a-b;
			}
		}
		else
		{
			for(i=0;i<n-1;++i)
			{
				num += prefix_pos[1-diff];
				diff += a-b;
			}
		}
		printf("%ld\n",num);
	}
}


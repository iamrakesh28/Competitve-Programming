#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

int possible(vector <int> &diff,int motu,int tomu,int k)
{
	int count=0;
	for(int i=0;i<diff.size();++i)
	{
		if(diff[i]>0)
		{
			count++;
			motu-=diff[i];
			tomu+=diff[i];
			if(tomu>motu)
			break;
		}
	}
	if(tomu>motu && count<=k)
	return 1;
	return 0;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,k,motu_sum=0,tomu_sum=0,val,size,d;
		vector < int > motu,tomu,diff;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&val);
			if(i%2==0)
			{
				motu.pb(val);
				motu_sum+=val;
			}
			else
			{
				tomu.pb(val);
				tomu_sum+=val;
			}
		}
		if(tomu_sum>motu_sum)
		{
			printf("YES\n");
			continue;
		}
		sort(motu.begin(),motu.end());
		sort(tomu.begin(),tomu.end());
		if(n%2==0)
		size = n/2;
		else
		size = n/2+1;
		for(int i=0;i<n/2;++i)
		{
			val = motu[size-1-i]-tomu[i];
			diff.pb(val);
		}
		int k_v=possible(diff,motu_sum,tomu_sum,k);
		//printf("%d\n",k_v);
		if(k_v)
		printf("YES\n");
		else
		printf("NO\n");
		
	}
	return 0;
}

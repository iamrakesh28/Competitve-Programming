#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

int round(int a, int b)
{
	if(a%b >= (float)b/2)
	return a/b+1;
	return a/b;
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		int n,l,ans=0,sum=0,val;
		scanf("%d%d",&n,&l);
		vector <int> lan ;
		for(int j=0;j<l;++j)
		{
			scanf("%d",&val);
			lan.pb(val);
			ans += round(100*lan[j],n);
			sum+=lan[j];
			if(100%lan[j]>=(float)n/2)
			{
				j--;
				l--;
				lan.pop();
			}
		}
		if(100%n>=(float)n/2)
		{
			ans += (n-sum)*(100/n+1);
			printf("Case #%d: %d\n",i,ans);
			continue;
		}	
		if(100%n==0)
		{
			ans += (n-sum)*(100/n);
			printf("Case #%d: %d\n",i,ans);
			continue;
		}	
		sort(lan.begin(),lan.end());
		
	}
	return 0;
}

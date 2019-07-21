#include <bits/stdc++.h>

#define square(x) (x*x)

using namespace std;

struct shop{
	long int price;
	long int index;
};

struct duk{
	long int price;
	long int loc;
};

bool cmp(shop a, shop b)
{
	return (a.price<b.price);
}

bool compare(shop a, shop b)
{
	return (a.loc<b.loc);
}
long int min(long int a,long int b)
{
	return a<b?a:b;
}

void sq_decom(int n,int m,duk *dukan,long int **k)
{
	int sq = sqrt(n);
	int res = n-sq*sq,begin=0;
	shop decm = new shop[n];
	for(int i=0;i<n;i+=sq)
	{
		for(int j=i;j<i+sq||j<n;j++)
		{
			decm[j].price = dukan[j].price + square(dukan[i].loc - dukan[j].loc);
			decm[j].index = j;
		}
		sort(decm+i,decm+min(i+sq,n),cmp);
	}
	for(int i=0;i<m;++i)
	{
		long int min_cost=INT_MAX;
		for(int j=0;j<n;j+=sq)
		{
			int ind = decm[j].index;
			if(dukan[j].loc <= cust_loc[i] && dukan[min(j+sq,n)].loc <= cust_loc[i])
			{
				int end = min(j+sq,n);
				for(int r=j;r<end;++i)
				{
					ind = decm[r].index;
					min_cost = min(min_cost,square(dukan[ind].loc-cust_loc[i]) + dukan[ind].price);	
				}
				continue;	
			}
			min_cost = min(min_cost,square(dukan[ind].loc-cust_loc[i]) + dukan[ind].price);
		}
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	duk *dukan = new duk[n];
	for(int i=0;i<n;++i)
	scanf("%ld%ld",&dukan[i].loc,&dukan[i].price);
	sort(dukan,dukan+n,compare);
	long int *cust_loc = new long int[m];
	int **k = new int*[m];
	for(int i=0;i<n;++i)
	{
		int ki; 
		scanf("%ld%d",cust_loc+i,&ki);
		if(ki>0)
		{
			k[i] = new int[km];
			for(int j=0;j<km;++j)
			scanf("%d",k[i]+j);
			sort(k[i],k[i]+km);
		}
		else
		ki[i] = NULL;
	}
	return 0;
}

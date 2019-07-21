#include <bits/stdc++.h>

#define ul unsigned long int
#define PRIME 1000000007

using namespace std;

ul multi(ul prod,ul time)
{
	ul r=1;
	while(time>0)
	{
		if(time%2) 
		r=(r*prod)%PRIME;
		prod = (prod*prod)%PRIME;
		time/=2;
	}
	return r;
}

void comb(int n,ul **combarr)
{
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			if(i == j || j == 0)
			{
				combarr[i][j] = 1;
				continue;
			}
			combarr[i][j] = combarr[i-1][j] + combarr[i-1][j-1];
		}
	}
}

ul solve(ul **product, int *seq, int n,int k,ul **combarr)
{
	ul prod = 1;
	for(int i=0;i<n;++i)
	{
		for(int j=n-1;j-i-1>=k-2;j--)
		{
			ul times = combarr[j-i-2][k-3];
			prod = (prod * multi(product[i+1][j-1],times))%PRIME;
		}
	}
	return prod;
}

int main()
{
	int q;
	scanf("%d",&q);
	ul **combarr = new ul*[5001];
	for(int i=0;i<5001;++i)
	combarr[i] = new ul[5001];
	comb(5000,combarr);
	while(q--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int *seq = new int[n];
		for(int i=0;i<n;++i)
		scanf("%d",seq+i);
		sort(seq,seq+n);
		ul **product = new ul*[n];
		for(int i=0;i<n;++i)
		{
			product[i] = new ul[n];
			ul prod = 1;
			for(int j=i;j<n;++j)
			{
				prod = product[i][j] = (prod*seq[j])%PRIME;
			}
		}
		ul ans = solve(product,seq,n,k,combarr);
		printf("%lu\n",ans);
	}
	return 0;
}


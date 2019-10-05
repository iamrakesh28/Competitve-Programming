#include <bits/stdc++.h>

#define ul unsigned long int
#define PRIME 1000000007
#define index(x) (x-n+r-1)

using namespace std;

ul multi(ul prod,ul time)
{
	ul r=1;
	while(time)
	{
		if(time%2) 
		r=(r*prod)%PRIME;
		prod = (prod*prod)%PRIME;
		time/=2;
	}
	return r;
}

ul min(ul a,ul b)
{
	return a<b?a:b;
}

ul comb(int n,int k,ul prod)
{
	int r = min(k,n-k);
	if(r<=0)
	return prod;
	int *num = new int[r];
	memset(num,0,sizeof(int)*r);
	for(int i=2;i<=r;++i)
	{
		int d = n/i;
		for(int j=d*i;j>n-r;j-=i)
		{
			if(num[index(j)]==0)
			{
				num[index(j)] = j/i;
				break;
			}
			else if(num[index(j)]%i == 0)
			{
				num[index(j)] = num[index(j)]/i;
				break;
			}
		}
	}
	for(int j=n;j>n-r;--j)
	{
		if(num[index(j)] == 0)
		{
			prod = multi(prod,j);
		}
		else
			prod = multi(prod,num[index(j)]);
	}
	return prod;
}

ul power(ul x,ul y)
{
    if (y == 0)
        return 1;
    ul p = power(x, y/2) % PRIME;
    p = (p * p) % PRIME;
 
    return (y%2 == 0)? p : (x * p) % PRIME;
}
 
ul solve(ul *product, int *seq, int n,int k)
{
	ul prod = 1;
	for(int i=0;n-i>=k;++i)
	{
		product[i]=comb(n-i-1,k-1,seq[i]);
		//cout<<product[i]<<endl;
		product[i] = power(product[i], PRIME-2);
		prod = (prod*product[i])%PRIME;
	}
	//prod = power(2, PRIME-2);
	for(int i=n-1;i>=k-1;--i)
	{
		product[i]=comb(i,k-1,seq[i]);
		//cout<<product[i]<<endl;
		product[i] = power(product[i], PRIME-2);
		prod = (prod*product[i])%PRIME;
	}
	return prod;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int *seq = new int[n];
		ul prod = 1;
		for(int i=0;i<n;++i)
		{
			scanf("%d",seq+i);
			prod = (prod*seq[i])%PRIME;
		}
		sort(seq,seq+n);
		if(n==k)
		{
			prod = (prod*power(seq[0],PRIME-2))%PRIME;
			prod = (prod*power(seq[n-1],PRIME-2))%PRIME;
			printf("%lu\n",prod);
			continue;
		}
		prod = comb(n-1,k-1,prod);
		//cout<<prod<<endl;
		ul *product = new ul[n];
		ul ans = solve(product,seq,n,k);
		printf("%lu\n",(ans*prod)%PRIME);
	}
	return 0;
}


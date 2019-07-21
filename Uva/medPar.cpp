#include <bits/stdc++.h>
#define PRIME 1000000007

using namespace std;

int A[1005];
long int TwoPower[1005];
long int nC[1005][1005];
long int Prefix[1005];
void power(void)
{
	long int r,a;
	for(int i=0;i<1005;++i)
	{
		r = 1,a=2;
		int n = i;
		while(n)
		{
			if(n & 1)
			r = (r*a)%PRIME;
			a = (a*a)%PRIME;
			n >>= 1;
		}
		TwoPower[i] = r;
	}	
}
void comb(void)
{
	for(int i=0,j;i<1005;++i)
	{
		for(j=0;j<=i;++j)
		{
			if(j == 0 || i == j)
			nC[i][j] = 1;
			else
			nC[i][j] = (nC[i-1][j-1] + nC[i-1][j])%PRIME;
		}
	}
	return;
}
int main()
{
	int q;
	scanf("%d",&q);
	power();
	comb();
	while(q--)
	{
		int n,side;
		long int ans = 0,r,val;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		scanf("%d",A+i);
		sort(A,A+n);
		ans = TwoPower[n-1];
		for(int i=0,j;i<n-1;++i)
		{
			for(j = i+1;j<n && A[i] == A[j];++j)
			{
				side = min(i,n-j-1);
				val = 1;
				/*
				for(int k=0;k<=side;++k)
				val = (val + nC[i][k]*nC[n-j-1][k])%PRIME;
				*/
				//vandermode's indentity
				val = nC[i+n-j-1][side];				
				ans = (ans + val)%PRIME;
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}


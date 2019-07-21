#include <bits/stdc++.h>
#define PRIME 1000000007

using namespace std;

int A[1005];
long int TwoPower[1005];
long int nC[1005][1005];
long int PrefixEven[1005][1005];
long int Prefix[1005][1005];
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
	for(int i=0,j;i<1005;++i)
	{
		for(j=0;j<=i;++j)
		{
			if(j == 0)
			{
				PrefixEven[i][j] = nC[i][j];
				Prefix[i][j] = 0;//nC[i][j];
				continue;
			}
			if(j % 2 == 0)
			PrefixEven[i][j] = (PrefixEven[i][j-2] + nC[i][j])%PRIME;
			Prefix[i][j] = (Prefix[i][j-1] + nC[i][j])%PRIME;
		}
	}
	for(int i=0,j;i<1005;++i)
	{
		for(j=1;j<=i;j++)
		{
			if(j % 2 == 0)
			{
				Prefix[i][j] = (Prefix[i][j] + Prefix[i][j-2] - nC[i][j/2] + PRIME)%PRIME;
				continue;
			}
			if(j == i)
			Prefix[i][i] = (Prefix[i][i] + Prefix[i][j-1] - nC[i][(j+1)/2] + PRIME)%PRIME;
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
				val = PrefixEven[n-j+i-1][2*side];
				r = (Prefix[i][min(2*side,i)] + Prefix[n-j-1][min(2*side,n-j-1)])%PRIME;
				val = (val - r + PRIME)%PRIME;
				ans = (ans + val)%PRIME;
			}
		}
		printf("%ld\n",ans);
	}
	return 0;
}

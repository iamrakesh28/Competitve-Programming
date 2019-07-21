#include <bits/stdc++.h>

using namespace std;

void testcase1(long int **C, long int p)
{
	for(int i=0;i<=2001;++i)
	{
		C[i] = new long int[2002];
		for(int j=0;j<=i;++j)
		{
			if(i == j || j == 0)
			{
				C[i][j] = 1;
				continue;
			}
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%p;
		}
	}
}

long int power(long int x,long int y,long int PRIME)
{
    if (y == 0)
        return 1;
    long int p = power(x, y/2,PRIME) % PRIME;
    p = (p * p) % PRIME;
 
    return (y%2 == 0)? p : (x * p) % PRIME;
}
int main()
{
	int q;
	long int p;
	cin>>q>>p;
	long int **C = new long int*[2002];
	testcase1(C,p);
	while(q--)
	{
		long int n,m;
		scanf("%ld%ld",&n,&m);
		if(m <= 1000)
		{
			printf("%ld\n",C[m+n-1][n-1]);
		}
	}
	return 0;
}

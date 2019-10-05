#include <bits/stdc++.h>

using namespace std;

long int length(long int n,long int k)
{
	if(k == 0)
    	return n;
	if(n == 2)
	return 1;
    	n = max((long int)2,n-2);
    	return length(n,k-1);
}
int main()
{
    	int q;
    	scanf("%d",&q);
    	while(q--)
    	{
        	long int n,k;
        	scanf("%ld%ld",&n,&k);
		long double p,len;
		if(n == 1)
		{
			p = 1;
			printf("%0.8Lf\n",p);
			continue;
		}
		if(n == 2)
		{
			p = 1/2.0;
			printf("%0.8Lf\n",p);
			continue;
		}
		if(n%2)
		n--,k--;
        	len = (long double)length(n,k);
        	p = 1/len;
        	printf("%0.8Lf\n",p);
    	}
    	return 0;
}


#include <bits/stdc++.h>

using namespace std;
long int found;
long int length(long int n,long int k)
{
	if(k == 0)
    	return n;
	if(n == 2)
	return 1;
	long int l,r;
	l = n/2;
	r = n-l;
	if(l == r && l % 2)
	{
		if(found == n)    	
		return length(l+1,k-1);
		return length(l,k-1);
	}
    	return length(max(l,r),k-1);
}
int main()
{
    	int q;
    	scanf("%d",&q);
    	while(q--)
    	{
        	long int n,k;
        	scanf("%ld%ld",&n,&k);
		double p,len;
		found = n;
		if(n == 1)
		{
			p = 1;
			printf("%lf\n",p);
			continue;
		}
		if(n == 2)
		{
			p = 1/2.0;
			printf("%lf\n",p);
			continue;
		}
        	len = (double)length(n,k);
        	p = 1/len;
        	printf("%lf\n",p);
    	}
    	return 0;
}


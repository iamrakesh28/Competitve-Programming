#include <stdio.h>

int main()
{
	long long int num = 600851475143,fac;
	if(num%2==0)
	{
		fac = 2;
		while(num%2==0)
		num/=2;
	}
	for(int i=3;i*i<=num;i+=2)
	{
		if(num%i==0)
		{
			fac = i;
			while(num%i==0)
			num/=i;
		}
	}
	if(num>2)
	fac=num;
	printf("%lld\n",fac);
	return 0;
}

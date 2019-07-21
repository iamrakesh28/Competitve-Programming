#include <stdio.h>

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int l,r,even;
		scanf("%ld%ld",&l,&r);
		even = r-l+1;
		if(even%2)
		{
			if(l%2)
			even = even/2 + 1;
			else	
			even = even/2;
		}
		else
		{
			even = even/2;
		} 
		if(even%2)
		printf("Odd\n");
		else
		printf("Even\n");
	}
	return 0;
}

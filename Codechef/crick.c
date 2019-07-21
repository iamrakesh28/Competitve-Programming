#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n,Rp,Wp,check =1;
	scanf("%d",&n);
	scanf("%d%d",&Rp,&Wp);
	n--;
	while(n--)
	{
		int Ri,Wi;
		scanf("%d%d",&Ri,&Wi);
		if(Ri<Rp)
		{
			check = 0;
		}
		if(Wi<Wp)
		{
			check = 0;
		}
		if(Wp == 10 && Ri > Rp)	
		{
			check = 0;
		}
		Rp = Ri, Wp = Wi;
		
	}
	if(check)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}

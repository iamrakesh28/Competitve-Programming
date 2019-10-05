#include <bits/stdc++.h>

using namespace std;

long int gcd(long int a,long int b)
{
	if(b == 0)
	return a;
	return gcd(b,a%b); 
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int n,t,x,y,z,p,q,f;
		scanf("%ld%ld%ld%ld%ld",&n,&t,&x,&y,&z);
		switch(t)
		{
			case 1 : if(x < y) // correct
					 {
							if(z == y-1)
							p = y-1;
							else
							p = 2*n-y;
					 }
					 else //correct
					 {
							if(z == y-1)
							p = 2*n+2-y;
							else
							p = y+1;
					 }
					 break;
			case 2 : 
			case 4 : 
					 if(x == z)
					 {					 
					    printf("0 1\n");
						continue;
					 }
					 p = 2*n + 1 - 2*y;
					 break; //correct
			default : //correct
					  if(y < z)
					  {
							if(x == y+1)
							p = y + 1;
							else
							p = 2*n + 2 - y;
					  }
					  else
					  {
							if(x == y+1)
							p = 2*n-y;
							else
							p = y-1;
					  }
		}
		q = 2*n + 1;
		f = gcd(p,q);
		//p = p/f;
		//q = q/f;
		printf("%ld %ld\n",p/f,q/f);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 int popcount(int x)
{
	int andmask,ones=0,one=1;
  	for(int i=31;i>=0;--i)
    {
      andmask=x&(one<<i);
      if(andmask!=0)
        ones++;
    }
	return ones;
}
int main() {

  	int q,l,r,maxp,maxnum;
  	scanf("%d",&q);
  	for(int i=0;i<q;++i)
    {
    	scanf("%d%d",&l,&r);
      	maxp=popcount(l);
      	maxnum=l;
      	for(int j=l;j<=r;++j)
        {
          int temp=popcount(j);
          if(temp>maxp)
          {
            maxp=temp;
            maxnum=j;
          }
        }
      printf("%d\n",maxnum);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
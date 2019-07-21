#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
  	scanf("%d",&n);
  	int *arr=(int *)malloc(sizeof(int)*n);
  	int sum=0;
  	for(int i=0;i<n;++i)
    {
      scanf("%d",arr+i);
      sum+=arr[i];
    }
  	int q=n/2,r=0,max=sum;
  	for(int i=2;q>=3;++i,q=n/i)
    {
      	
      	sum=0;
      	if(n%i==0)
        {
          for(int k=0;k<i;++k)
	{
      		for(int j=k;j<n;j+=i)
        	{
            	sum+=arr[j];
        	}
	
		if(sum>max)
         	 max=sum;
		sum=0;
	}
        }
	//printf("%d\n",sum);
      	
	
    }
  	printf("%d\n",max);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
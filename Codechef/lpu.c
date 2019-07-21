#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	long int evsum=0,odsum=0;
  	scanf("%d",&n);
  	int *arr=(int *)malloc(n*sizeof(int));
  	for(int i=0;i<n;++i)
    {
      scanf("%d",arr+i);
      if(arr[i]%2==0)
        evsum+=arr[i];
      else
      {
        odsum+=arr[i];
        if(odsum%2==0)
        {
          evsum+=odsum;
          odsum=0;
        }
      }
    }
  	//max=0;
  	
    
  	printf("%ld\n",evsum);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
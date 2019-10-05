#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
  	scanf("%d",&n);
  	int *arr=(int *)malloc(sizeof(int)*n);
  	for(int i=0;i<n;++i)
    {
      	scanf("%d",arr+i);
    }
  	printf("%d %d\n",arr[1]-arr[0],arr[n-1]-arr[0]);
  	for(int i=1;i<n-1;++i)
    {
      	int left,right,lmax,rmax;
      	left=arr[i]-arr[i-1];
      	right=arr[i+1]-arr[i];
      	if(left<right)
          printf("%d ",left);
      	else
          printf("%d ",right);
      	rmax=arr[n-1]-arr[i];
      	lmax=arr[i]-arr[0];
      	if(lmax>rmax)
          printf("%d\n",lmax);
      	else
          printf("%d\n",rmax);
    }
  	printf("%d %d\n",arr[n-1]-arr[n-2],arr[n-1]-arr[0]);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
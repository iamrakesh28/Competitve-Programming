#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,m,pos=0,time=0;
  	scanf("%d%d",&n,&m);
  	int *arr=(int *)malloc(sizeof(int)*m);
  	for(int i=0;i<m;++i)
    {
      	scanf("%d",arr+i);
    }
  	for(int i=0;i<m;++i)
    {
      	if(arr[i]-1>pos)
        {
          	time+=arr[i]-1-pos;
          	pos=arr[i]-1;
        }
      	else if(arr[i]-1<pos)
        {
          	time+=n-1-pos+arr[i];
          	pos=arr[i]-1;
        }
    }
  	printf("%d\n",time);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
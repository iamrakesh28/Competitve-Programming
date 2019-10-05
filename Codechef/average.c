#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct exam{ 
  	int grade,bi;
} T; 

void sort(T *arr,int n)
{
  for(int i=0;i<n-1;++i)
    for(int j=0;j<n-1-i;++j)
  	{
    	if(arr[j].bi>arr[j+1].bi)
    	{
      	T temp;
      	temp=arr[j+1];
      	arr[j+1]=arr[j];
      	arr[j]=temp;
    	}
  	}
}
int main() {

  int n,r,avg,sum=0,avgsum,min=0;
  scanf("%d%d%d",&n,&r,&avg);
  avgsum=n*avg;
  T *arr=(T *)malloc(sizeof(T)*n);
  for(int j=0;j<n;++j)
  {
    	int grade,bi;
  		scanf("%d%d",&grade,&bi);
    	arr[j].grade=grade;
    	arr[j].bi=bi;
    	sum+=grade;
  }
  sort(arr,n);
  int diff=avgsum-sum;
  for(int i=0;diff>0;)
  {
    	if(arr[i].grade<r)
        {
          min+=arr[i].bi, diff--;
          arr[i].grade+=1;
        }
    	else
          ++i;
  }
  printf("%d",min);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
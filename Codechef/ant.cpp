#include <bits/stdc++.h>

using namespace std;
long int maxStackHeight(long int *arr, int n)
{
	long int msh[n],weight=0;
   	for (int i = 0; i < n; i++ )
      	msh[i] = 1;
	for (int i = 1; i < n; i++ )
	     { 
		weight=0;			
for (int j = 0; j < i; j++ )
 			if (msh[i] < msh[j] + 1 && weight <6*arr[i])
 		             {
				  msh[i] = msh[j] + 1;
					weight+=arr[j];
 				}
 
 }
   /* Pick maximum of all msh values */
   long int max = -1;
   for ( int i = 0; i < n; i++ )
      if ( max < msh[i] )
         max = msh[i];
 
   return max;
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		int n;
		scanf("%d",&n);
		long int *arr = (long int*)malloc(sizeof(long int)*n);
		for(int j=0;j<n;++j)
		{
			scanf("%ld",arr+j);
		}
		long int h=maxStackHeight(arr,n);
	printf("Case #%d: %ld\n",i,h);
	}
	return 0;
}

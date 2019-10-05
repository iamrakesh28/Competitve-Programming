#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int prime(int *arr,int n)
{
    int i,j,count=1;
    for(i=3;count<n;++i)
    {
        arr[count]=i;
        for(j=0;i%arr[j]!=0;++j);
        if(arr[j]==i)
            count++;      
    }
    return arr[count-1];
}

int main(){
    int t; 
    scanf("%d",&t);
    for(int a = 0; a < t; a++){
        int n; 
        scanf("%d",&n);
        int *arr=(int *)malloc(n*sizeof(int));
        arr[0]=2;
        printf("%d\n",prime(arr,n));
    }
    return 0;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 100
int* sum(int *B,int n)
{
    int *A=(int *)calloc(MAX,sizeof(int));
    int *C=(int *)malloc(MAX*sizeof(int));
    for(int i=n-2;i>=0;--i)   
    {
        for(int j=1;j<=B[i];++j)
        {
            int num=(j-1)+A[0];
            for(int k=2;k<=j;++k)
            {
               int num1=(j-k)+A[k-1];
                if(num1>num)
                    num=num1;
            }
            for(int k=j+1;k<=B[i+1];++k)
            {
               int num1=(k-j)+A[k-1];
                if(num1>num)
                    num=num1;
            }
            C[j-1]=num;
        }
        for(int ri=0;ri<B[i];++ri)
            A[ri]=C[ri];
    }
    return A;
}

int main() {
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;++i)
    {
        int n;
        scanf("%d",&n);
        int *B=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;++j)
            scanf("%d",&B[j]);
        int *A=sum(B,n);
        int lar=A[0];
        for(int j=1;j<B[0];++j)
        {
            if(A[j]>lar)
                lar=A[j];
        } 
        printf("%d\n",lar);
    }
    return 0;
}

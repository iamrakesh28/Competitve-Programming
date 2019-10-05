#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
long sum(long int *A,int j)
{
    int sum=0;
    for(int i=0;i<=j;++i)
        sum+=A[i];
    return sum;
}
void comb(long int *A, int i,long int *b,int len,int n,int d,int j,long int *rb,int k)
{
    
    for(i;i<=len-n;++i)
    {
        b[j]=A[i];
        if(j>0)
        d+=pow(i-j,2);
        if(n!=1)
        comb(A,i+1,b,len,n-1,d,j+1,rb,k);
        else
        {
            
            if((sum(b,j)-k*d)>=(*rb))
                (*rb)=(sum(b,j)-k*d);
            d=0;
        }
    }
}
long int modifiedSubsequenceSum(int n, int k, long int* A) {
    long int ra=0; long int *rb;long int b[n];
    for(int i=1;i<=n;++i)
    {
        comb(A,0,b,n,i,0,0,&ra,k);
    }
    return ra;
}

int main() {
    int n; 
    int k; 
    scanf("%i %i", &n, &k);
    long int *A = malloc(sizeof(long int) * n);
    for (int A_i = 0; A_i < n; A_i++) {
       scanf("%li",&A[A_i]);
    }
    long int result = modifiedSubsequenceSum(n, k, A);
    printf("%ld\n", result);
    return 0;
}


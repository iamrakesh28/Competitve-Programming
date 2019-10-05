#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void update1(int l, int r,int *A)
{
    for(int i=l-1;i<=r-1;++i)
        A[i]+=1;
}
void update2(int i, int v, int *A)
{
    A[i-1]=v;
}
int larg(int l, int r,int *A)
{
    int large=A[l-1];
    for(int i=l;i<=r-1;++i)
    {
        if(A[i]>large)
            large=A[i];
    }
    return large;
}
long int fact(int large, long int *a)
{
    if(large!=1)
    {
        a[large]=large*fact(large-1,a);
        return a[large];
    }
    else
        return 1;
   // return 1;
}
int main() {
    int n; 
    int m; 
    scanf("%i %i", &n, &m);
    int *A = malloc(sizeof(int) * n);
    for (int A_i = 0; A_i < n; A_i++) {
       scanf("%i",&A[A_i]);
    }
    for(int a0 = 0; a0 < m; a0++){
        int i,l;
        int r;
        scanf("%i%i%i",&i,&l,&r);
        if(i==1)
            update1(l,r,A);
        else if(i==3)
            update2(i,r,A);
        else
        {
            int large=larg(l,r,A);
            long int *a=(long int*)malloc(large*sizeof(long int));
            a[0]=a[1]=1; long int lar=fact(large,a); lar=0;
            for(int i=l-1;i<=r-1;++i)
            {
                lar+=a[A[i]]; //printf("%ld \n",lar);
            }
            //lar=lar%1000000000;
            printf("%ld\n",lar); //free(a);
        }
    }
    return 0;
}

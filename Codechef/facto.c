#include<stdio.h>
#include<stdlib.h>
unsigned long int fact(long int n, unsigned long int *a)
{
    const unsigned int M = 1000000000;
 
    unsigned long int f = 1;
    for (int i = 1; i <= n; i++)
    {   
        f = (f*i) % M; 
        a[i]=f; // Now f never can
    }              // exceed 10^9+7
    return f;
}
int main()
{
long int large=100000;
const unsigned long int m=1000000000;
unsigned long int *a=(unsigned long int*)malloc((large+1)*sizeof(unsigned long int));
            a[0]=a[1]=1; unsigned long int lar=fact(large,a); 
long int b;
scanf("%ld",&b);
printf("\n%ld %ld",a[b],m);

return 0;
}
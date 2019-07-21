#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
long fact(long n)
{
    int c;
    if(n%2==0)
    {
        if(n/2==1)
            return 2;
        else
           c=fact(n/2);
    }
    else
    {
        for(int i=3;i<=n;i+=2)
        {
            if(n%i==0)
            {
                if(n/i==1)
                    return i;
                else
                    c=fact(n/i);
            }
        }
    }
	return c;
    
}
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        long n; 
        scanf("%ld",&n);
        printf("%ld\n",fact(n));
    }
    return 0;
}

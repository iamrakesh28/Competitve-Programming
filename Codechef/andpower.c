#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

unsigned long int power_two(unsigned long int n,unsigned long int *index)
{
     unsigned long int power, i;
    for(i= *index;i>=0;--i)
    {
        power = 1ull<<i;
	//printf("=%ld=%ld=%ld",power,i,n);
        if((power&n)!=0)
        {
            *index = i;
            return power;
        }
    }
    return power;
}

char* counterGame(unsigned long int n) {
    unsigned long int power,index=63;
    int winner=1;
    //power = power_two(n,&index);
    while(n!=1)
    {
        if((n&(n-1))==0)
        {
           n>>1;
        }
        else
        {
            	power = power_two(n,&index);
		n=n-power;
        }
	
        winner++;
    }
    if(winner%2==0)
        return "Richard";
    return "Louise";
    
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        unsigned long int n; 
        scanf("%lu", &n);
        int result_size;
        char* result = counterGame(n);
        printf("%s\n", result);
    }
    return 0;
}

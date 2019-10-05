#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int recursion(int X, int N, int sum,int start)
{
    int count=0,i=start+1;
    int num=sum;//+=pow(i,N);
    sum=pow(i,N)+num;
    for(;sum<X; ++i)
    {
        sum=pow(i,N)+num;
        count+=recursion(X,N,sum,i);
        //sum=pow(i,N)+num;
    }
    if(sum==X)
        return ++count;
    else
        return count;    
}
int powerSum(int X, int N) {
   return recursion(X,N,0,0);
}

int main() {
    int X; 
    scanf("%i", &X);
    int N; 
    scanf("%i", &N);
    int result = powerSum(X, N);
    printf("%d\n", result);
    return 0;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int leftfun(int n,int* height, int* position,int i)
{
    int j;
    for(j=i+1;j<n;++j)
    {
        if(position[j]-position[i]>height[i])
        {
            return j;
        }
    }
    return j;
}

int rightfun(int n,int* height, int* position,int i)
{
    int j;
    for(j=i-1;j>=0;--j)
    {
        if(position[i]-position[j]>height[i])
        {
            return j;
        }
    }
    return j;
}
char* checkAll(int n,int* height, int* position) {
    // Complete this function
    int left=1,right=1,val;
    for(int i=0;i<n-1;)
    {
        val=leftfun(n,height,position,i);
        if(val==i+1)
        {
            left=0;
            break;
        }
        else
        {
            i=val-1;
        }
    }
    for(int i=n-1;i>0;)
    {
        val=rightfun(n,height,position,i);
        if(val==i-1)
        {
            right=0;
            break;
        }
        else
        {
            i=val+1;
        }
    }
    if(left&&right)
        return "BOTH";
    if(left)
        return "LEFT";
    if(right)
        return "RIGHT";
    return "NONE";
}

int main() {
    int n; 
    scanf("%i", &n);
    int *position = malloc(sizeof(int) * n);
    for (int position_i = 0; position_i < n; position_i++) {
       scanf("%i",&position[position_i]);
    }
    int *height = malloc(sizeof(int) * n);
    for (int height_i = 0; height_i < n; height_i++) {
       scanf("%i",&height[height_i]);
    }
    //int result_size;
    char* ret = checkAll(n, height, position);
    printf("%s\n", ret);
    return 0;
}

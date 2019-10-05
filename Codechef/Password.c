#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int comparison(char **pass, int *a, char *attempt)
{
    int i=0;
    char *pt=pass[a[i]];
    while(*attempt!='\0')
    {
       if(*pt=='\0')
       {    
           i++;
           pt=pass[a[i]];
       }
        if(*attempt!=*pt)
            return 0;
        pt++, attempt++;
    }
    return 1;
}

int recursion(int attemptlen, int n, int *a, char **pass, char *attempt, int *count, int len,int *strln)
{
    if(len<attemptlen)
    {
        for(int i=0;i<n;++i)
        {
        
            a[(*count)++]=i;
            if(recursion(attemptlen,n,a,pass,attempt,count,len+strln[i],strln))
            return 1;
            (*count)--;
        }
        return 0;
    }
    else if(len==attemptlen)
        return comparison(pass,a,attempt);
    else
        return 0;  
}

char* passwordCracker(int n, char** pass, char* attempt) 
{
    int *a=(int *)malloc(2000*sizeof(int));
    int count=0,*ptcount;
    ptcount=&count;
    int attemLen=strlen(attempt);
    int *strln=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;++i)
    {
        strln[i]=strlen(pass[i]);
    }
    if(recursion(attemLen,n,a,pass,attempt,ptcount,0,strln))
    {
        char *arr=(char *)malloc((attemLen+count)*sizeof(char));
        strcpy(arr,pass[a[0]]);
        for(int i=1;i<count;++i)
        {
            strcat(arr," ");   
            strcat(arr,pass[a[i]]);
        }
        return arr;
    }
    else
        return "WRONG PASSWORD";
}
int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%i", &n);
        char **pass = malloc(sizeof(char*) * n);
        for (int pass_i = 0; pass_i < n; pass_i++) {
           pass[pass_i] = (char *)malloc(10240 * sizeof(char));
           scanf("%s",pass[pass_i]);
        }
        char* attempt = (char *)malloc(512000 * sizeof(char));
        scanf("%s", attempt);
        int result_size;
        char* result = passwordCracker(n, pass, attempt);
        printf("%s\n", result);
    }
    return 0;
}

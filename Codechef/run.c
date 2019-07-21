#include <string.h>
#include <stdio.h>


typedef struct {
    int value;
    char nm[10];
} nam;

void checker(int *value,int *x, int *y)
{
        
    
         int rem=(*value)%10;
        *value=*value/10;
        switch(rem)
        {
            case 4 :(*x)++; break;
            case 7 :(*y)++; break;
            default:(*value)=-1;
        }
        if((*value)>=1)
            checker(value,x,y);
    
}
int main() {
    int n,x=0,y=0;
    scanf("%i",&n);
    nam start; start.value=0;
    for(int a = 0; a < n; a++)
    {
        char name[10];
        int value1,value2;
        scanf("%s %d",name,&value1);
        value2=value1;
        checker(&value1,&x,&y);
       if(value1>=0&&x==y)
       {  
           if(!start.value)
             {
               start.value=value2;
               strcpy(start.nm,name);
             }
           if(start.value>value2)
            { 
               start.value=value2;
               strcpy(start.nm,name); 
            }
       }
        x=y=0;
    }
    if(start.value)
       printf("%s",start.nm);
    else
        printf("-1");
    return 0;
}


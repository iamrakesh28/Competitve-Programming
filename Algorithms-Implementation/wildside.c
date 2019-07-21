#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    long double u0,b,num,num1,p1,p2,d1,d2;
    long int val,i=1;
    scanf("%Lf%Lf",&u0,&b);
    num=u0; p1=pow(10,-16); p2=pow(10,9);
    num1=((int)pow(2,b-num*num))/p2;
    d2=num-num1;
    while(1)
    {
		
           val=pow(2,b-num1*num1);
           num=val/p2;
        if(i%2)
            d1=num-num1;
        else
            d2=num-num1;
       //printf("%Lf %Lf",d1,d2);
		if((d1+d2)*(d1+d2)<=p1)
		break;
		else
        {
            num1=num; 
        }
        ++i;
    }
    printf("%0.9Lf",num+num1);
    return 0;
}

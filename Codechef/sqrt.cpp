#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long int sig(long int m,long int d)
{
    long int beg=1, end=m*d,start; float check;
    float sq=sqrt(m); //cout<<end;
    for(;end-beg!=1;)
    {  
       start=(beg+end)/2; 
        check=(float)start/d; //cout<<check<<"\t";
        if((check)>sq)
        {end=(beg+end)/2;} //cout<<end;}
        else
        { beg=(beg+end)/2; }//cout<<beg;}
    }
    
    if((pow((float)beg/d-sq,2))>=pow((float)end/d-sq,2))
        return end;
    else
        return beg;
}

long int app(int m,int d)
{
    long int num=0, deno=1, sum=0,var;
    for(long int i=2;i<=m;++i)
    {  //cout<<"hello";
        float check=sqrt(i);
        long int inc=sqrt(i);
        if(check!=inc)
        { //cout<<i;
        for(long int j=d;j>=1;j--)
        {
             var=sig(i,j); //cout<<var<<"\t"<<j<<endl;
           //cout<<num<<"\t"<<deno<<endl;
            if((pow((float)var/j-check,2))<=pow((float)num/deno-check,2))
            { num=var; deno=j;}
        }
        }
        sum+=deno;
    }
    return sum;
}
int main() {
    long int m,d;
    cin>>m>>d;
    cout<<app(m,d);
    return 0;
}

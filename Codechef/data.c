#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct var{
    int x[3];
} st;
int checker(int [],st);
void query(char *ch, st *point,int A[][100][100])
{
    char check[6];
    int num[3][2],sum=0;
    sscanf(ch,"%s%d%d%d%d%d%d",check,num[0][0],num[1][0],num[2][0],num[0][1],num[1][1],num[2][1]);
    while(*point!='\0')
    {
        if(checker(num,point))
            sum+=A[point->x[0]][point->x[1]][point->x[2]];
        point++;
    }
    printf("%d",sum);
}
int checker(int num[][2], st *point)
{
    for(int i=0;i<3;++i)
    {
        int h=point->x[i];
        if(num[i][0]<=h&&num[i][1]>=h)
            return 1;
    }
    return 0;
}
int main() {
    long int A[100][100][100];   
    int q;
    scanf(%d,&q);
    for(int i=1;i<=q;++i)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        st *store=malloc(sizeof(st)*m);
        st *point=store;
        char *ch=malloc(sizeof(char)*20);
        for(int j=1;j<=m;++j)
        {
            gets(ch);
            char check[6];
            sscanf(ch,"%s",check);
            if(!strcmp(check,"UPDATE"))
            {
                int x,y,x,w;
                sscanf(ch,"%s%d%d%d%d",check,x,y,z,w);
                A[--x][--y][--z]=w;
                store->x[0]=x;
                store->x[1]=y;
                store->y[2]=z;
                store++;
            }    
            else
            {
                query(ch,point,A);
            }
                    
        }
    }
    return 0;
}

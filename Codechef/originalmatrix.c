#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int num1=-250,num2=-250,num=-250;
void perl(int i, int j, int A[][500], int sum,int n,int m)
{
        for(;j>=0;--j)
        {
            if(i<n-1)
            {
                (sum)+=A[i][j];
                perl(i+1,j,A,sum,n,m);
            }
            else
            {
                for(int t=j;j<m;++t)
                (sum)+=A[i][j];
                if(num1<=(sum))
                    num1=(sum);
            }
        }
}
void per(int i, int j, int A[][500], int sum,int n, int m)
{
          // perl(i,j,A,sum,n,m);
            if(j<=m-1)
            {
                if(i<n-1)
                {
                    (sum)+=A[i][j];
                    per(i+1,j,A,sum,n,m);
                      sum-=A[i][j];
                }
                (sum)+=A[i][j];
                per(i,j+1,A,sum,n,m);
                
                if(num2<(sum))
                 num2=(sum); 
                if(num1<num2)
                    num=num2;
                else
                    num=num1;
            }
   }

int matrixLand(int n, int m, int  A[][500],int sum) {
    //for(int r=0;r<m;++r)
    //{
         //printf("%d\n",num);
       //per(0,0,A,sum,n,m);
        perl(0,0,A,sum,n,m);
   
    return num;
}
    int main() {
    int n; 
    int m,sum=0; 
    scanf("%i %i", &n, &m);
    int A[500][500];
    for (int A_i = 0; A_i < n; A_i++) {
       for (int A_j = 0; A_j < m; A_j++) {
      
          scanf("%i",&A[A_i][A_j]);
       }
    }
         //printf("%d\n",num);
    int result = matrixLand(n, m, A,sum);
    printf("%d\n", result);
    return 0;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int num1=-250,num2=-250,num=-250;
void perl(int i, int j, int A[][500], int sum,int n,int m)
{
   int a;
   a=A[i][j]; 
    if(j>=0&&j<=m-1&&i<=n-1)
    {
        sum+=A[i][j];
        A[i][j]=0;
        perl(i,j-1,A,sum,n,m);
    
    //if(j<=m-1)
    //{
        //sum+=A[i][j];
        //A[i][j]=0;
        perl(i,j+1,A,sum,n,m);
    //}
    //if(i<=n-1)
    //{
        //sum+=A[i][j];
        //A[i][j]=0;
        perl(i+1,j,A,sum,n,m);
    }
    A[i][j]=a;
}
void per(int i, int j, int A[][500], int sum,int n, int m)
{
          // perl(i,j,A,sum,n,m);
            if(j<=m-1)
            {
                if(i<n-1)
                {
                    (sum)+=A[i][j];
                    per(i+1,j,A,sum,n,m);
                      sum-=A[i][j];
                }
                (sum)+=A[i][j];
                per(i,j+1,A,sum,n,m);
                
                if(num2<(sum))
                 num2=(sum); 
                if(num1<num2)
                    num=num2;
                else
                    num=num1;
            }
   }

int matrixLand(int n, int m, int  A[][500],int sum) {
    //for(int r=0;r<m;++r)
    //{
         //printf("%d\n",num);
       //per(0,0,A,sum,n,m);
        perl(0,0,A,sum,n,m);
   
    return num;
}
    int main() {
    int n; 
    int m,sum=0; 
    scanf("%i %i", &n, &m);
    int A[500][500];
    for (int A_i = 0; A_i < n; A_i++) {
       for (int A_j = 0; A_j < m; A_j++) {
      
          scanf("%i",&A[A_i][A_j]);
       }
    }
         //printf("%d\n",num);
    int result = matrixLand(n, m, A,sum);
    printf("%d\n", result);
    return 0;
}


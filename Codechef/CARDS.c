#include <stdio.h>
#include <stdlib.h>

int sort(int *A,int *D,int n,int *B)
{
	int num,max=0,i;
	for(i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;++j)
		{
			if(A[j]>A[j+1])
			{
				num=A[j];
				A[j]=A[j+1];
				A[j+1]=num;
				num=D[j];
				D[j]=D[j+1];
				D[j+1]=num;
				
			}
		}
		max+=D[n-1-i];
		if(max>=B[0])
		break;
	}
	//if(i!=n)
	return n-1-i;
	//else
	//return i;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,k,sum=0;
		scanf("%d%d",&n,&k);
		int *A=(int *)malloc(sizeof(int)*n);
		int *D=(int *)malloc(sizeof(int)*n);
		int *B=(int *)malloc(sizeof(int)*k);
		for(int i=0;i<n;++i)
		{
			scanf("%d",A+i);
		}
		for(int i=0;i<n;++i)
		{
			scanf("%d",D+i);
		}
		for(int i=0;i<k;++i)
		{
			scanf("%d",B+i);
		}
		int begin=n-1,end,residue,temp,j;
		end=(A,D,n,B);
		num=B[i];
		for(int j=end;j<=begin;++j)
		{
			sum+=D[j];
		}
		residue=sum-B[0];
		/*temp=end;
		end=begin;
		begin=temp;*/
		for(int i=1;i<k;++i)
		{
			num=B[i]-residue;
			if(i%2)
			{
				for(j=end;sum<=num;++j)
				{
					sum+=D[j];
				}
				residue=sum-num;
				begin=j-1;
			}
			else
			{
				for(j=begin;sum<=num;--j)
				{
				sum+=D[j];
				}
				residue=sum-num;
				end=j+1;
			}
		}
		num=B[i]-residue;
		if(k%2)
			{
				for(j=end;sum<=num;++j)
				{
					sum+=D[j];
				}
				residue=sum-num;
				//begin=j-1;
			}
			else
			{
				for(j=begin;sum<=num;--j)
				{
				sum+=D[j];
				}
				residue=sum-num;
				//end=j+1;
			}
	printf("%d\n",sum);
	}
	return 0;
}

#include <bits/stdc++.h>

#define size 1000
#define array(x) (count + x)

using namespace std;

long int calculate(int diff,int count,int *prefix,vector <int> &seq,int n)
{
		vector <int > :: iterator it;
		long int num=0;
		int i,pres=diff;
		//diff = 0;
		for(it=seq.begin();it!=seq.end();it++)
		{
			prefix[array(*it)]++;
		}
		for(i=2*count;i>0;--i)
		{
			prefix[i-1] += prefix[i];
		}
		i = 1;
		while(abs(diff)<=count && i <= n)
		{
			num+=(long int)prefix[count+1-diff];
			diff+=pres;
			++i;
			//
		}
		//diff = diff-pres;
		i--;
		//printf("%ld %ld",abs(diff),diff);
		//
		if(abs(diff)>count)
		{
			
			if(i<n)
			{
				if(diff>0)
				{
					num+=(long int)count*(n-i);
					//prlong intf("%ld ",count);
				}
			}			
		}
		return num;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char string[size+1];
		 long int num=0;
		int i=0,count,a=0,b=0,diff,n;
		vector <int> seq;
		scanf("%s%d",string,&n);
		while(string[i]!='\0')
		{
			if(string[i]=='a')
			{
				a++;
			}
			else
			{
				b++; 
			}
			diff = a-b;
			if(diff>0)
			{
				num++;
			}
			seq.push_back(a-b);
			i++;
		}
		count  = i;
		if(diff==0)
		{
			printf("%ld\n",num*n);
			continue;
		}
		//long int *prefix = new long int [2*count+1];
		//memset(prefix,0,sizeof(long int)*(2*count+1));
		//sort(seq.begin(),seq.end());
		int *prefix = (int *)calloc(2*count+1,sizeof(int));
		num+=calculate(diff,count,prefix,seq,n-1);
		printf("%ld\n",num);
	}
	return 0;
}


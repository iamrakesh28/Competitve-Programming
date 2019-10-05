#include <bits/stdc++.h>

#define ul long long int

using namespace std;

struct tree{
	long long int min;
	vector <int> *seq;
};

ul minimum(ul a,ul b,int *num)
{
	if(a<b)
	{
		*num=1;
		return a;
	}
	*num=2;
	return b;
}

void merge(vector <int> *small,vector <int> *big)
{
	for(int i=0;i<small->size();++i)
	{
		big->push_back(small->at(i));
	}
	
}
void infinity(long long int *arr,int n,int pos,int count,ul *sum)
{
	//printf("%d=%d=",pos,count);
	int num;
	tree *node = new tree[count];
	for(int i=count-1;i>=0;--i)
	{
		int val = 2*i+pos;
		if(i+2 < count)
		{
			if(i+3 < count)
			{
				node[i].min=minimum(node[i+2].min,node[i+3].min,&num)-2*arr[val];
				node[i].seq = new vector<int> [1];
				if(num==1)
				{
					 merge(node[i+2].seq,node[i].seq);
				
				}
				else
				{
					merge(node[i+3].seq,node[i].seq);
				}
				node[i].seq[0].push_back(val);
			}
			else
			{
				node[i].min=node[i+2].min-2*arr[val];
				node[i].seq = new vector<int> [1];
				merge(node[i+2].seq,node[i].seq);
				node[i].seq[0].push_back(val);
				//node[i].seq[1].push_back(val);
			}
		}
		else
		{
			node[i].min=sum[n]-2*arr[val];
			node[i].seq = new vector<int> [1];
			node[i].seq[0].push_back(val);
			//seq[1].push_back(val);
		}
	}
	int j=0;
	if(node[0].min > node[1].min)
	{
		j=1;
	}
	for(int i=0;i<node[j].seq[0].size();++i)
	{
		int val=node[j].seq[0][i];
		arr[val]=(-1)*arr[val];
	}
}

void peak(long long int *arr,bool *mark,int n,ul *sum)
{
	long long int val;
	if(arr[0]>=arr[1])
	mark[0]=false;
	else
	mark[0]=true;
	for(int i=1;i<n-1;++i)
	{
		if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
		mark[i]=true;
		else
		mark[i]=false;			
	}
	if(arr[n-1]<arr[n-2])
	mark[n-1]=true;
	else
	mark[n-1]=false;
	for(int i=0;i<n;++i)
	{
		if(mark[i]==true)
		{
			if(i<n-2 && mark[i+2]==true)
			{
				val=sum[i+3]-sum[i]-2*arr[i]-2*arr[i+2];
				if(val<=0)
				continue;
			}
			if(i>=2 && mark[i-2]==true)
			{
				val=sum[i+1]-sum[i-2]-2*arr[i]-2*arr[i-2];
				if(val <= 0)
				{
					continue;
				}
			}
			mark[i]=false;
			arr[i]=(-1)*arr[i];
		}	
	}
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,count=0,pos;
		scanf("%d",&n);
		long long int *arr = new long long int[n];
		bool *mark = new bool[n];
		ul *sum = (ul*)malloc((n+1)*sizeof(ul));
		scanf("%lld",arr);
		sum[0]=0;
		sum[1] = arr[0];		
		for(int i=1;i<n-1;++i)
		{
			scanf("%lld",arr+i);
			sum[i+1] = arr[i]+sum[i];
		}
		scanf("%lld",arr+n-1);
		sum[n] = arr[n-1]+sum[n-1];
		peak(arr,mark,n,sum);
		int j;	
		for(j=0;j<n;++j)
		{
			if(mark[j]==true)
			{
				count++;
				j++;
			}
			else if(j>=2 && mark[j-2]==true)
			{
				pos=j-2*(count);
				infinity(arr,n,pos,count,sum);
				count=0;
			}
		}
		if(j>=2 && mark[j-2]==true)
		{
			pos=j-2*(count);
			infinity(arr,n,pos,count,sum);
			count=0;
		}
		for(int i=0;i<n;++i)
		{
			printf("%lld ",arr[i]);
		}
		printf("\n");
	}
	
}

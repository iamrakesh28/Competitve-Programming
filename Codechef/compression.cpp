#include <bits/stdc++.h>

using namespace std;

struct Element{
	int index;
	unsigned long int val,key;
};

bool compare(Element A, Element B)
{
	return (A.val < B.val);
}

int left(int i,int k)
{
	if(i-k > 0)
	return i-k;
	return 0;
}
int right(int n,int k,int i)
{
	if(i+k <= n-1)
	return i+k;
	return n-1;
}

unsigned long int maxm(unsigned long int a,unsigned long int b)
{
	return a>b?a:b;
}

unsigned long int smallest(int n,int k,Element *element,int index)
{
	unsigned long int max = 0,max_same=0;
	for(int i=index-1;i>=0;--i)
	{
		if(element[i].index >= left(element[index].index,k) && element[i].index <= right(n,k,element[index].index))
		{
			if(element[i].val != element[index].val)
			{
				max = maxm(max,element[i].key);
			}
			else
			{
				max_same = maxm(max_same,element[i].key);
			}
		}
	}
	max++;
	max = maxm(max,max_same);
	for(int i=index-1;i>=0;--i)
	{
		if(element[i].index >= left(element[index].index,k) && element[i].index <= right(n,k,element[index].index))
		{
			if(element[i].val == element[index].val)
			{
				element[i].key = max;
			}
		}
	}
	return max;
}

bool possible(int k,int n,Element *element,unsigned long int s)
{
	unsigned long int sum=0,num;
	//element[0].key = 1;
	for(int i=0;i<n;++i)
	{
		element[i].key = 0;
	}
	for(int i=0;i<n;++i)
	{
		element[i].key = num = smallest(n,k,element,i);
		//sum += num;
		//printf("%d[%d] ",num,element[i].index);
	}
	for(int i=0;i<n;++i)
	{
		sum += element[i].key;
	}
	//sum++;
	cout<<sum<<"\t";
	if(sum<=s)
	return true;
	return false;
}

int solve(int n,unsigned long int s,Element *element)
{
	int begin=0,end=n,middle;
	while(begin<=end)
	{
		middle = (begin+end)/2;
		//printf("=%d=",middle);
		if(possible(middle,n,element,s))
		{
			begin = middle+1;
		}
		else
		end = middle-1;
	}
	if(possible(middle,n,element,s))
	{
		begin = middle+1;
	}
	else
		begin = middle;
	return begin;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		unsigned long int s;
		scanf("%d%lu",&n,&s);
		Element *element = new Element[n];
		for(int i=0;i<n;++i)
		{
			scanf("%ld",&element[i].val);
			element[i].index = i;
			
		}
		sort(element,element + n,compare);
		int num = solve(n,s,element);
		printf("%d\n",num);
	}
	return 0;
}

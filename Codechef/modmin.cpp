#include <bits/stdc++.h>

#define ul unsigned long int
#define PRIME 1000000007

using namespace std;

ul multi(ul prod,ul time)
{
	ul r=1;
	while(time)
	{
		if(time%2) 
		r=(r*prod)%PRIME;
		prod = (prod*prod)%PRIME;
		time/=2;
	}
	return r;
}

ul min(ul a,ul b)
{
	return a<b?a:b;
}

void factors(int c,vector <int> &arr)
{
	if(c%2==0)
	{
		while(c%2==0)
		{
			c = c/2;
			arr.push_back(2);
		}
	}
	for(int i=3;i*i <= c;i+=2)
	{
		if(c%i == 0)
		{
			while(c%i==0)
			{
				arr.push_back(i);
				c = c/i;
			}
		}
	}
	if(c>2)
	{
		arr.push_back(c);
	}
	return;
}
void merge(vector <int> &real, vector <int> &exp,vector <int> &arr)
{
	int count=1,i;
	for(i=1;i<arr.size();++i)
	{
		if(arr[i] == arr[i-1])	
		{
			count++;
		}
		else
		{
			exp.push_back(count);
			count = 1;
			real.push_back(arr[i-1]);
		}
	}
	exp.push_back(count);
	real.push_back(arr[i-1]);
	return;
}

ul comb(int n,int k,ul prod,vector <int> *adj)
{
	int r = min(k,n-k);
	if(r==0)
	return prod;
	vector <int> arr,temp;
	vector <int> :: iterator it;
	for(int i=n;i>n-r;--i)
	{
		
		for(it = adj[i-1].begin();it != adj[i-1].end();++it)
		{
			arr.push_back(*it);
		}
	}
	sort(arr.begin(),arr.end());
	for(int i=1;i<=r;++i)
	{
		for(it = adj[i-1].begin();it != adj[i-1].end();++it)
		{
			temp.push_back(*it);
		}
	}
	sort(temp.begin(),temp.end());
	vector <int> arr_real,arr_exp,temp_real,temp_exp;
	merge(arr_real,arr_exp,arr);
	merge(temp_real,temp_exp,temp);
	for(int i=0;i<temp_real.size();++i)
	{
		int j=0;
		int begin = 0,end = arr_real.size()-1,middle;
		while(begin<=end)
		{
			middle = (begin+end)/2;
			if(arr_real[middle] == temp_real[i])
			{
				j = middle; break;
			}
			else if(arr_real[middle] > temp_real[i])
			{
				end = middle-1;
			}
			else
				begin = middle+1;
		}
		/*for(j=0;j<arr_real.size();++j)
		{
			if(temp_real[i] == arr_real[j])
			break;
		}*/
		arr_exp[j]-=temp_exp[i];
	}
	for(int i=0;i<arr_real.size();i++)
	{
		if(arr_exp[i])
		{
			prod = multi(prod,arr_real[i]);
			prod = multi(prod,arr_exp[i]);
		}
	}
	return prod;
}

ul power(ul x,ul y)
{
    if (y == 0)
        return 1;
    ul p = power(x, y/2) % PRIME;
    p = (p * p) % PRIME;
 
    return (y%2 == 0)? p : (x * p) % PRIME;
}
 
ul solve(ul *product, int *seq, int n,int k,vector <int> *adj)
{
	ul prod = 1;
	for(int i=0;n-i>=k;++i)
	{
		product[i]=comb(n-i-1,k-1,seq[i],adj);
		//cout<<product[i]<<endl;
		product[i] = power(product[i], PRIME-2);
		prod = (prod*product[i])%PRIME;
	}
	//prod = power(2, PRIME-2);
	for(int i=n-1;i>=k-1;--i)
	{
		product[i]=comb(i,k-1,seq[i],adj);
		//cout<<product[i]<<endl;
		product[i] = power(product[i], PRIME-2);
		prod = (prod*product[i])%PRIME;
	}
	return prod;
}

int main()
{
	int q;
	scanf("%d",&q);
	vector <int> *adj;
	adj = new vector<int>[10000];
	adj[0].push_back(1);
	for(int i=1;i<10000;++i)
	{
		adj[i].push_back(1);
		factors(i+1,adj[i]);
	}
	while(q--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int *seq = new int[n];
		ul prod = 1;
		for(int i=0;i<n;++i)
		{
			scanf("%d",seq+i);
			prod = (prod*seq[i])%PRIME;
		}
		sort(seq,seq+n);
		if(n==k)
		{
			prod = (prod*power(seq[0],PRIME-2))%PRIME;
			prod = (prod*power(seq[n-1],PRIME-2))%PRIME;
			printf("%lu\n",prod);
			continue;
		}
		prod = comb(n-1,k-1,prod,adj);
		ul *product = new ul[n];
		ul ans = solve(product,seq,n,k,adj);
		printf("%lu\n",(ans*prod)%PRIME);
	}
	return 0;
}


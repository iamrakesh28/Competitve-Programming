#include <bits/stdc++.h>

using namespace std;

class line {
	public :
	int k;
	int b;
	line(int k_, int b_) : k(k_), b(b_) {}
};
int gcd(int a, int b)
{
	if(b == 0)
	return a;
	return gcd(b,a%b);
}

void find(vector <line> &cont,int k,int b)
{
	vector <line> :: iterator it;
	for(it = cont.begin();it != cont.end();++it)
	{
		if((*it).k == k && (*it).b == b)
		{
			cont.erase(it);
			break;
		}
	}
}
int sol(vector <line> &cont,int q)
{
	int count = 0,num;
	vector <line> :: iterator it;
	for(it = cont.begin(); it!= cont.end(); ++it)
	{
		line sb = *it;
		num = q - sb.b;
		if(num % sb.k == 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);	
	vector <line> cont ;
	while(n--)
	{
		int k,b,q,num;
		char ch;
		vector <line> :: iterator it;
		scanf(" %c",&ch);
		switch(ch)
		{
			case '+':  scanf("%d%d",&k,&b); 
				   if(b%gcd(k,-1)==0)
				   {	
					cont.push_back(line(k,b));
				   }
				   break;
			case '-' : scanf("%d%d",&k,&b);
				   find(cont,k,b);
				   break;
			default :  scanf("%d",&q);
				   num = sol(cont,q);
				   printf("%d\n",num);
		
		}
	}
}

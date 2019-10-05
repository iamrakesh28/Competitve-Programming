#include <bits/stdc++.h>

using namespace std;

string multiply(string X,string Y)
{
	int n1 = X.size();
	int n2 = Y.size();
	if(n1 == 0 || n2 == 0)
	{
		return "0";
	}
	vector <int> result(n1+n2,0);
	int a=0,b;
	for(int i=n1-1;i>=0;i--)
	{
		b = 0;
		int num1 = X[i] - '0';
		int carry = 0 ;
		for(int j=n2-1;j>=0;j--)
		{
			int num2 = Y[j] - '0';
			int sum = num1*num2 + result[a+b] + carry;
			carry = sum/10;
			result[a+b] = sum%10;
			b++;
		}
		if(carry)
		result[a+b] += carry;
		a++;
	}
	int len = result.size()-1;
	while(len>=0 && result[len] == 0)
	len--;
	if(len == -1)
	return "0";
	string s = "";
	while(len>=0)
	s+= std::to_string(result[len--]);
	return s;
	
}

int main()
{
	string X,Y;
	cin>>X;
	cin>>Y;
	cout<<multiply(X,Y)<<endl;
	return 0;
}

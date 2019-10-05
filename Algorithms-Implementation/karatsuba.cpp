#include <bits/stdc++.h>

using namespace std;

int makeEqualLength(string &x, string &y)
{
	int len1 = x.size();
	int len2 = y.size();
	if(len1<len2)
	{
		for(int i=0;i<len2-len1;++i)
		x = '0' + x;
		return len2;
	}
	else if(len1 > len2)
	{
		for(int i=0;i<len1-len2;++i)
		y = '0' + y;
	}
	return len1;
}

string add(string first,string second)
{
	string result;
	int length = makeEqualLength(first,second);
	int carry = 0;
	char res;
	for(int i=length-1;i>=0;i--)
	{
		int num1 = first.at(i) - '0';
		int num2 = second.at(i) - '0';
		int sum = num1 + num2 + carry;
		res = (sum%10) + '0';
		result = res + result;
		carry = sum/10;
	}
	res = carry + '0';
	if(carry)
	result = res + result;
	return result;
}

string digitMultiply(string x,string y)
{
	int num1 = x.at(0) - '0';
	int num2 = y.at(0) - '0';
	int prod = num1*num2;
	string result;
	char res = prod%10 + '0';
	result = res + result;
	res = prod/10 + '0';
	result = res + result;
	return result;
}
string subtract(string x,string y)
{      //Positive result assumption
	string result;
	int length = makeEqualLength(x,y);
	int carry = 0 ;
	char res;
	for(int i=length-1;i>=0;i--)
	{
		int num1 = x.at(i) - '0';
		int num2 = y.at(i) - '0';
		int diff = num1-num2 + carry;
		if(diff<0)
		{
			diff = diff + 10;
			carry = -1;
		}
		else
		carry = 0;
		res = diff + '0';
		result = res + result;
	}
	return result;
}

string multiply(string x, string y)
{
	int n = makeEqualLength(x,y);
	if(n==0)
	return "0";
	if(n == 1)
	return digitMultiply(x,y);
	int fh = n/2;
	int sh = n-fh;
	string X1 = x.substr(0,fh);
	string X0 = x.substr(fh,sh);
	string Y1 = y.substr(0,fh);
	string Y0 = y.substr(fh,sh);
	string P1 = multiply(X0,Y0);
	string P2 = multiply(X1,Y1);
	string P3 = multiply(add(X0,X1),add(Y0,Y1));
	P3 = subtract(P3,P1);
	P3 = subtract(P3,P2);
	int i=0,len = P3.size();
	while(i < len && P3.at(i++) == '0');
	string res;
	i--;
	while(i < len)
	res = res + P3.at(i++);
	for(i=0;i<sh;++i)
	res = res + '0';
	res = add(res,P1);
	for(i=0;i<2*sh;++i)
	P2 = P2 + '0';
	return add(P2,res);
}

int main()
{
	string x ;//= "544";
	string y ;//= "3454544";
	//makeEqualLength(x,y);
	cin>>x>>y;
	string result = multiply(x,y);
	int i=0,len = result.size();
	while(i < len && result.at(i++) == '0');
	string res;
	i--;
	while(i < len)
	res = res + result.at(i++);
	cout<<res<<endl;
	return 0;
}

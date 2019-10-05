#include <bits/stdc++.h>

using namespace std;

string fun(string &a)
{
	a[0] = 'Y';
	return a;
}
int main()
{
	string a = "Rakesh";
	map<string,int> p[10];
	p[0].insert({a,2});
	//cout<<p.at(a);
	//if(a == "Rakeh")
	cout<<p[0].count(a)<<endl;
	return 0;
}

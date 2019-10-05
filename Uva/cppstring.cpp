#include <bits/stdc++.h>

using namespace std;
int main()
{
	vector <int> a = {3,5,6};
	auto it = lower_bound(a.begin(),a.end(),2);
	cout<<it-a.begin()<<"\n";
	return 0; 
}

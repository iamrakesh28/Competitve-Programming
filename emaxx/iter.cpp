#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> V = {1,2,3};
	auto it = V.begin();
	*it = 5;
	cout<<V[0]<<" "<<V[1]<<" "<<V[2]<<endl;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c;
	scanf("%d%d",&a,&b);
	vector <int> p;
	if(b%2 && b%10 != 1)
	printf("NO\n");
	else {
		p.push_back(b);
		while(b >= a) {
			if(b == a) {
				cout<<"YES\n"<<p.size()<<endl;
				for(auto it=p.rbegin();it!=p.rend();++it)
					cout<<*it<<" ";
				cout<<"\n";
				return 0;
			}
			if(b%2) {
				if(b%10 != 1) {
					printf("NO\n");
					return 0;
				}
				p.push_back(b/10);
				b = b/10;
			}
			else {
				p.push_back(b/2);
				b = b/2;
			}
		}
		printf("NO\n");
	}
	return 0;
}

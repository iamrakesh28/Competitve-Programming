#include <bits/stdc++.h>

using namespace std;

int main()
{
	char arr[15],ans[15],*p;
	scanf("%s",arr);
	int len = strlen(arr);
	for(int i = len-1;i>0;i--) {
		if(arr[i] <= '0') {
			arr[i-1] -= 1;
			for(int j=i;j<len;++j) 
				arr[j] = 9 + '0';
		}
	}
	p = arr;
	if(arr[0] == '0') {
		p = arr+1;
	}
	len = strlen(p);
	for(int i = 0;i < len-1;i++) {
		int a = (p[i]-'0')*(p[i+1]-'0');
		int b = (p[i]-1-'0')*(9);
		if(b >= a) {
			p[i] = p[i]-1;
			for(int j=i+1;j<len;++j)  {
				p[j] = '9'; 
			}
			goto lb;
		}
	}
	lb:
	cout<<p<<endl;
	long long res = 1;
	for(int i=0;i<len;++i) {
		res = res*(p[i]-'0');
	}
	cout<<res<<endl;
	return 0;
}

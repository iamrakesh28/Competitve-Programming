#include <bits/stdc++.h>

using namespace std;

int x[505], y[505], p, NS[505], EW[505], dp[505][100000], dpE[505][100000];
char d[505];

int solveN(int i, int x1) 
{
	cout<<i<<" "<<x1<<endl;
	if (i == p)
		return 0;	
	if (dp[i][x1] == -1) {
		if (d[i] == 'S') {
			if (y[i] - 1 >= x1) {
				dp[i][x1] = solveN(i + 1, x1) + 1;
				NS[i] = 1;
			}
			else {
				dp[i][x1] = solveN(i + 1, x1);
			}
		}
		else if(d[i] == 'N') {
			int a = solveN(i + 1, max(x1,y[i] + 1)) + 1;
			int b = solveN(i + 1, x1);
			if (a > b) {
				dp[i][x1] = a;
				NS[i] = 1;
			}
			else
				dp[i][x1] = b; 
		}
		else
			dp[i][x1] = solveN(i + 1, x1);
	}
	return dp[i][x1];
}

int solveE(int i, int x1) 
{
	if (i == p)
		return 0;	
	if (dpE[i][x1] == -1) {
		if (d[i] == 'W') {
			if (x[i] - 1 >= x1) {
				dp[i][x1] = solveE(i + 1, x1) + 1;
				EW[i] = 1;
			}
			else {
				dp[i][x1] = solveE(i + 1, x1);
			}
		}
		else if(d[i] == 'E') {
			int a = solveE(i + 1, max(x1,x[i] + 1)) + 1;
			int b = solveE(i + 1, x1);
			if (a > b) {
				dpE[i][x1] = a;
				EW[i] = 1;
			}
			else
				dpE[i][x1] = b; 
		}
		else
			dpE[i][x1] = solveE(i + 1, x1);
	}
	return dpE[i][x1];
}
int main()
{
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; ++i) {
		int q, ansx0, ansx1, ansy0, ansy1;
		scanf("%d%d",&p,&q);
		ansx0 = q;
		ansx1 = 0;
		ansy0 = q;
		ansy1 = 0;
		for (int j = 0; j < p; ++j) {
			scanf("%d%d%c",x+j,y+j,d+j);
			NS[j] = 0;
			EW[j] = 0;
			memset(dp[j],-1,sizeof(int)*(q+5));
			memset(dpE[j],-1,sizeof(int)*(q+5));
			/*if (d == 'N') {
				ansy1 = max(ansy1, y + 1);
			}
			else if (d == 'S') {
				ansy0 = min(ansy0, y - 1);
			}
			else if (d == 'E') {
				ansx1 = max(ansx1, x + 1);
			}
			else
				ansx0 = min(ansx0, x - 1);*/
		}
		int a = solveN(0,0);
		int b = solveE(0,0);
		cout<<a<<" "<<b<<endl;
		for (int i = 0; i < p; ++i) {
			if (EW[i] == 1) {;
			}	
			else if(NS[i] == 1) {;
			}
		}
		printf("Case #%d: %d %d\n",i+1, min(ansx0, ansx1), min(ansy0, ansy1));
	}
	return 0;
}

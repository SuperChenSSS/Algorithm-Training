#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
int n,m;
const int maxn = 1e3;
const int maxm = 1e3;
char s[maxn],t[maxm];
int dp[maxn+1][maxm+1];//DP数组
using namespace std;
int main() {
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<m;i++)
			cin>>t[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(s[i] == t[j])
					dp[i+1][j+1] = dp[i][j] + 1;
				else
					dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
//此条件中w[maxn]和v[maxn]都很大，需要降低复杂度
//思路：从用DP针对不同重量限制计算最大的价值
//     到用DP针对不同的价值计算最小的重量
const int maxn = 1e3,maxv = 1e3,INF = 1e6;
int w[maxn],v[maxn];
int dp[maxn+1][maxn*maxv+1];
int n,W;
using namespace std;
int main() {
	while(cin>>n>>W)
	{
		for(int i=0;i<n;i++)
			cin>>w[i]>>v[i];
		fill(dp[0],dp[0] + maxn * maxv + 1,INF);
		dp[0][0] = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=maxn * maxv;j++)
			{
				if(j<v[i])
					dp[i+1][j] = dp[i][j];
				else
					dp[i+1][j] = min(dp[i][j],dp[i][j - v[i]] + w[i]);
			}
		int res = 0;
		for(int i=0;i<=maxn*maxv;i++)
			if(dp[n][i]<=W)
				res = i;
		cout<<res<<"\n";
	}
	return 0;
}
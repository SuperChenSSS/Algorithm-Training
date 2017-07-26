#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
const int maxn = 1e3;
int n,W;
const int maxw = 1e3;
//int dp[maxn+1][maxw+1];
int w[maxn],v[maxn];//DP数组
int dp[maxn+1];//DP数组
using namespace std;
int main() {
	while (cin>>n>>W) {
		for(int i=0;i<n;i++)
			cin>>w[i]>>v[i];
		//DP处理优化版
		/*for(int i=0;i<n;i++)
			for(int j=0;j<=W;j++)
			{
				if(j<w[i])
					dp[i+1][j] = dp[i][j];
				else
					dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]] + v[i]);
			}
		*/
		//重复利用数组
		for(int i=0;i<n;i++)
			for(int j=w[i];j<=W;j++)
			{
				dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
			}
		cout<<dp[W]<<"\n";
		//cout<<dp[n][W]<<"\n";
	}
	return 0;
}
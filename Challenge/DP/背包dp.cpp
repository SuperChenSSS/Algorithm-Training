#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
const int maxn = 1e3;
int n,W;
int w[maxn],v[maxn];
//int dp[maxn+1][maxn+1];
int dp[maxn+1];
using namespace std;
int main() {
	while (cin>>n>>W) {
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			cin>>w[i]>>v[i];
		/*for(int i=n-1;i>=0;i--)
			for(int j=0;j<=W;j++)
			{
				if(j<w[i])
					dp[i][j] = dp[i+1][j];
				else
					dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
			}
		cout<<dp[0][W]<<"\n";*/
		//逆向版
		/*for(int i=0;i<n;i++)
			for(int j=0;j<=W;j++)
			{
				if(j<w[i])
					dp[i+1][j] = dp[i][j];
				else
					dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]] + v[i]);
			}
		cout<<dp[n][W]<<"\n";*/
		//分离成两个状态版
		/*for(int i=0;i<n;i++)
			for(int j=0;j<=W;j++)
			{
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
				if(j+w[i]<=W)
					dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j] + v[i]);
			}
			cout<<dp[n][W]<<"\n";
		*/
		//二维转一维，重复利用数组
		for(int i=0;i<n;i++)
			for(int j=W;j>=w[i];j--)
			{
				dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
			}
		cout<<dp[W]<<"\n";
	}
	return 0;
}
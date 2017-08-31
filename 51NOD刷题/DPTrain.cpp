#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e3;
int arr[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	int n;
	memset(arr,0,sizeof(arr));
	memset(dp,0,sizeof(dp));
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>arr[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + arr[i][j];
			}
		cout<<dp[n][n]<<endl;
	}
}
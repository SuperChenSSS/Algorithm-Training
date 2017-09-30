#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e3;
const int mod = (1e9+7); 
int a[maxn],dp[maxn][maxn];
//多重集组合数：有n种物品，每种物品有ai个，不同种类物品互相区分但相同物品无法区分
//从这些数中取m个的话，有多少种取法？
int main()
{
	freopen("4.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n,m,M;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}		
		cin>>M;
		//一个都不取的方法总是只有一种
		for(int i=0;i<=n;i++)
			dp[i][0] = 1;
		for(int i=0;i<n;i++)
			for(int j=1;j<=m;j++)
			{
				if(j-1-a[i]>=0)
				{//在有取余的情况下，要避免减法运算的结果出现负数
					dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]] + M) % M;
				}
				else
				{
					dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]) % M;
				}
			}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
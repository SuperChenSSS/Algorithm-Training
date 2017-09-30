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
int dp[maxn][maxn+1];
//划分数：有n个无区别的物品，将它们划分成不超过m组，求划分方法%M的余数
int main()
{
	freopen("3.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n,m,M;
	while(cin>>n>>m>>M)
	{
		dp[0][0] = 1;
		for(int i=1;i<=m;i++)
			for(int j=0;j<=n;j++)
			{
				if(j-i>=0)
					dp[i][j] = (dp[i-1][j]+dp[i][j-i]) % M;
				else
					dp[i][j] = dp[i-1][j];
			}
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
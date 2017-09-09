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
int dp[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n)
	{
		for(int i=0;i<m;i++)
			dp[i][0] = 1;
		for(int i=0;i<n;i++)
			dp[0][i] = 1;
		for(int i=1;i<m;i++)
			for(int j=1;j<n;j++)
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
				if(dp[i][j]>mod)
					dp[i][j] %= mod;
			}
		cout<<dp[m-1][n-1]<<endl;
	}
	return 0;
}
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
const int maxn = 1e3+5;
const int mod = (1e9+7); 
int T,cas = 0;
int n,m;
int dp[maxn][maxn];
char s[maxn],t[maxn];
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>s>>t)
	{
		int n = strlen(s),m = strlen(t);
		for(int i=0;i<=n;i++)
			dp[i][0] = i;
		for(int i=0;i<=m;i++)
			dp[0][i] = i;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));
			}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
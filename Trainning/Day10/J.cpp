//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue>  
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int mod = 1000000007;  
const int maxn = (1e3+10);
ll dp[maxn][maxn];
int arra[maxn],arrb[maxn];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>arra[i];
		for(int i=1;i<=m;i++)
			cin>>arrb[i];
		dp[0][0]=dp[1][0]=dp[0][1]=0;  
		memset(dp,0,sizeof(dp));  
		for(int i=1;i<=n;i++)   
			for(int j=1;j<=m;j++)  
				if(arra[i]!=arrb[j])  
					dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;   
				else  
					dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%mod;  
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}
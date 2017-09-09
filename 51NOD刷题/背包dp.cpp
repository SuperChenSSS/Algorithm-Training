#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
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
const int INF = 1000000000;  
const int maxn = 1e3;
const int mod = (1e9+7); 
int w[maxn],p[maxn];
int dp[maxn][maxn];
int n,W;
int main()
{
	ios::sync_with_stdio(false);
	memset(w,0,sizeof(w));
	memset(p,0,sizeof(p));
	memset(dp,0,sizeof(dp));
	cin>>n>>W;
	for(int i=0;i<n;i++)
		cin>>w[i]>>p[i];
	/*for(int i=0;i<n;i++)
		for(int j=W;j>=0;j--)
		{
			if(j<w[i])
				dp[i+1][j] = dp[i][j];
			else
				dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+p[i]);
		}
	cout<<dp[n][W]<<endl;*/
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<=W;j++)
		{
			if(j<w[i])
				dp[i][j] = dp[i+1][j];
			else
				dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + p[i]);
		}
	cout<<dp[0][W]<<"\n";
	/*for(int i=0;i<n;i++)
		for(int j=W;j>=w[i];j--)
		{
			dp[j] = max(dp[j],dp[j - w[i]] + p[i]);
		}
	cout<<dp[W]<<"\n";*/
	return 0;
}
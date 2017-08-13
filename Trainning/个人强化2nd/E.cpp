//TDteam01
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
const int maxn = 1e6;
const int mod = (1e9+7); 
char arr[maxn];
int dp[maxn][2],len;
int main()
{
	while(cin>>(arr+1))
	{
		len = strlen(arr+1);
		arr[len+1] = '0';
		dp[0][0] = -1,dp[0][1] = 1;
		for(int i=1;i<=len+1;i++)
			dp[i][0] = INF,dp[i][1] = INF;
		for(int i=0;i<=len;i++)
		{
			if(arr[i+1]=='1')
			{
				dp[i+1][0] = min(dp[i+1][0],dp[i][0]+2);
				dp[i+1][1] = min(dp[i+1][1],dp[i][1]);
				dp[i+1][0] = min(dp[i+1][0],dp[i][1]+2);
			}
			else
			{
				dp[i+1][0] = min(dp[i+1][0],dp[i][1]+2);
				dp[i+1][0] = min(dp[i+1][0],dp[i][0]);
				dp[i+1][1] = min(dp[i+1][1],dp[i][0]+2);
				dp[i+1][1] = min(dp[i+1][1],dp[i][1]+2);
			}
		}
		cout<<max(0,dp[len+1][0])<<"\n";
	}
	return 0;
}
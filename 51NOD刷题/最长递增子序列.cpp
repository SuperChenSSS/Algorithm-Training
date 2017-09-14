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
const int maxn = 1e6;
const int mod = (1e9+7); 
int dp[maxn];//dp[i]表示递增数量i的最小值
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,len = 1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[len] = a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]>dp[len])
			dp[++len] = a[i];
		else
		{
			int pos = lower_bound(dp+1,dp+len,a[i]) - dp;
			//在dp[]找第一个>=a[i]下标
			dp[pos] = a[i];
		}
	}
	cout<<len<<endl;
	return 0;
}
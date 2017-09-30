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
int dp[maxn],n,a[maxn];
//求最长上升子序列的长度
//dp[i]:长度为i+1的上升子序列中末尾元素的最小值(不存在的话就是INF)
int main()
{
	freopen("2.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		fill(dp,dp+n,INF);
		for(int i=0;i<n;i++)
			*lower_bound(dp,dp+n,a[i]) = a[i];
		cout<<lower_bound(dp, dp+n, INF) - dp <<endl;	
	}
	return 0;
}
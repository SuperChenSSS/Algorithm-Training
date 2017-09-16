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
const int MAXN = 50010;
int dp[MAXN][20];
int mm[MAXN];
//初始化RMQ,b数组下标从1开始，从0开始简单修改
void initrmq(int n,int b[])
{
	mm[0] = -1;
	for(int i = 1; i <= n;i++)
	{
		mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
		dp[i][0] = b[i];
	}
for(int j = 1; j <= mm[n];j++)
	for(int i = 1;i + (1<<j) -1 <= n;i++)
		dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

//查询最大值
int rmq(int x,int y)
{
	int k = mm[y-x+1];
	return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	initrmq(n,a);
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<rmq(l+1,r+1)<<endl;
	}
	return 0;
}
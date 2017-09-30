#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
const int maxn = 1e6;
using namespace std;
int dp[maxn],a[maxn],m[maxn];
int main() 
{
	ios::sync_with_stdio(false);
	freopen("1.txt","r",stdin);
	int n,k;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>m[i];
		cin>>k;
		memset(dp,-1,sizeof(dp));
		dp[0] = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++)
				if(dp[j]>=0)
					dp[j] = m[i];
				else if(j<a[i] || dp[j-a[i]]<=0)
					dp[j] = -1;
				else
					dp[j] = dp[j-a[i]] - 1;
		if(dp[k]>=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
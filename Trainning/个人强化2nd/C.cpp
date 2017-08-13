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
const int maxn = 4000;
const int mod = (1e9+7); 
int root[maxn],dp[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,maxx,tmp,x;
	cin>>n;
	memset(root,0,sizeof(root));
	maxx = 0;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		root[x]++;
		if(maxx<x)
			maxx = x;
	}
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i=maxx;i>=1;i--)
	{
		if(root[i]!=0)
			for(int j=n;j>=root[i];j--)
				if(dp[j-root[i]]!=0)
					if(dp[j]!=0)
						dp[j] = min(dp[j],dp[j-root[i]]+1);
					else
						dp[j] = dp[j-root[i]] + 1;
	}
	for(int i=0;i<n;i++)
		if(dp[i])
		{
			if(i==n-1)
				cout<<dp[i]-1;
			else
				cout<<dp[i]-1<<" ";
		}
		else
		{
			if(i==n-1)
				cout<<-1;
			else
				cout<<-1<<" ";
		}
	cout<<"\n";
	return 0;
}
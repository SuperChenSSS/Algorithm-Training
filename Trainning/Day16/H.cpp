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
const int INF = 0x3f3f3f3f;  
const int maxn = 1e3+10;
const int mod = (1e9+7); 
int arr[maxn][maxn];
bool vis[maxn];
int lowc[maxn];
int Prim(int cost[][maxn],int n)
{
	int ans = 0;
	memset(vis,false,sizeof(vis));
	vis[0] = true;
	for(int i=1;i<n;i++)
		lowc[i] = cost[0][i];
	for(int i=1;i<n;i++)
	{
		int minc = INF;
		int p = -1;
		for(int j=0;j<n;j++)
			if(!vis[j] && minc>lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		if(minc==INF)	return -1;
		ans += minc;
		vis[p] = true;
		for(int j=0;j<n;j++)
			if(!vis[j] && lowc[j]>cost[p][j])
				lowc[j] = cost[p][j];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n,m,kas = 1;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		ll ans = Prim(arr, n*m);
		printf("Case #%d:\n%lld\n",kas++,ans);
	}
	return 0;
}
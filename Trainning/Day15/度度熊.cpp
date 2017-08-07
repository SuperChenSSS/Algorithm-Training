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
const int maxn = 1e6,maxm = 1005;
const int mod = (1e9+7); 
ll a[maxn],b[maxn],k[maxn],p[maxn];
ll dp[maxm][15];//防御力为j，打出i点伤害以上时所需的最少晶石

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		ll up1 = 0,up2 = 0,hp = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			up1 = max(up1,b[i]);
			hp = max(hp,a[i]);
		}
		for(int i=0;i<m;i++)
		{
			cin>>k[i]>>p[i];
			up2 = max(up2,p[i]);
		}
		if(up1>=up2)
		{
			cout<<"-1\n";
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=10;i++)//防御
			for(int j=1;j<=hp;j++)//造成的伤害
			{
				dp[j][i] = INF;
				for(int u=0;u<m;u++)//第u个技能
				{
					ll dmg = p[u] - i;
					if(dmg<=0)
						continue;
					if(dmg>=j)
						dp[j][i] = min(dp[j][i],k[u]);
					else
						dp[j][i] = min(dp[j][i],dp[j-dmg][i]+k[u]);
				}
			}
		ll ans = 0;
		for(int i=0;i<n;i++)
			ans += dp[a[i]][b[i]];
		cout<<ans<<"\n";
	}
	return 0;
}
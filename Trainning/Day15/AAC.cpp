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
const int M = 1e6;  
const long mod = 1e9+7;  
int vis[M],a[M],l[M],r[M];  
int main()  
{  
	int n;  
	while(cin>>n)  
	{  
		memset(l,0,sizeof(l));  
		memset(r,0,sizeof(r));  
		memset(vis,0,sizeof(vis));  
  
		for(int i = 1;i <= n; i++)  
		{  
			cin>>a[i];
			r[i] = n+1;  
			for(int j = a[i];j <= 10000; j+=a[i])  
			{  
				if(vis[j])  
				{  
					r[vis[j]] = i;  
					vis[j] = 0;  
				}  
			}  
			vis[a[i]] = i;  
		}  
		memset(vis,0,sizeof(vis));  
		for(int i = n;i >= 1; --i)  
		{  
			for(int j = a[i];j <= 10000; j+=a[i])  
			{  
				if(vis[j])  
				{  
					l[vis[j]] = i;  
					vis[j] = 0;  
				}  
			}  
			vis[a[i]] = i;  
		}  
  
		ll ans = 0;  
		for(int i = 1;i <= n; ++i)  
		{  
			ans = ((ans + (ll)(r[i]-i)*(ll)(i-l[i])%mod)%mod);  
		}  
  
		cout<<ans<<"\n";  
	}  
}  
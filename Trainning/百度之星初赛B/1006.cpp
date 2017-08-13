//@Team: TDteam01
//@Author: CMY
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
typedef unsigned long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const ll INF = 1000000000;  
const ll maxn = 1e6;
const int mod = (1e9+7); 
bool state1[maxn],state2[maxn];
ll l[maxn],r[maxn];
ll n,m;
ll ans = 0,maxm = 0,minm = INF;
ll judge(int i)
{
	if(i==maxm && state2[i]==true && m>0)
	{
		ans += 1 + m;
	}
	else if(i==maxm && state2[i]==false && m>0)
	{
		ans += m;
	}
	else if(state2[i]==true)
		ans++;
	else if(state2[i]==false && m>0)
	{
		ans++;
		state2[i] = true;
		m--;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		ans = 0,maxm = 0,minm = INF;
		for(ll i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
			for(ll j=l[i];j<=r[i];j++){
				if(j<maxm)
					state1[j] = true;
				else
					state2[j-maxn] = true;
			}
			maxm = max(maxm,r[i]);
			minm = min(minm,l[i]);
		}
		for(int i=minm;i<=maxm;i++)
		{
			if(i>maxn){
				ans = judge(i);
				continue;
			}
			if(i==maxm && state1[i]==true && m>0)
			{
				ans += 1 + m;
			}
			else if(i==maxm && state1[i]==false && m>0)
			{
				ans += m;
			}
			else if(state1[i]==true)
				ans++;
			else if(state1[i]==false && m>0)
			{
				ans++;
				state1[i] = true;
				m--;
			}
			else
				break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
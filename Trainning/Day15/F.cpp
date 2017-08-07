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
int arr[10];
ll f(ll x,ll m)
{
	ll ans = 0;
	if(x<10)
		ans = x;
	else
	{
		for(int i=0;i<10;i++)
			ans = (ans + arr[i] * f(x-1-i,m) % m) % m;
	}
	return ans;
}
int main()
{
	ll k,m,ans;
	while(cin>>k>>m)
	{
		ans = 0;
		for(int i=0;i<10;i++)
			cin>>arr[i];
		ans = f(k,m);
		cout<<ans<<"\n";
	}
	return 0;
}
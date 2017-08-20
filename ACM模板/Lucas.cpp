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
const ll mod=1000000007;

ll ans;

ll quick_mod(ll a, ll b)
{
	ll ans = 1;
	a %= mod;
	while(b)
	{
		if(b & 1)
		{
			ans = ans * a % mod;
			b--;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

ll C(ll n, ll m)
{
	if(m > n) return 0;
	ll ans = 1;
	for(int i=1; i<=m; i++)
	{
		ll a = (n + i - m) % mod;
		ll b = i % mod;
		ans = ans * (a * quick_mod(b, mod-2) % mod) % mod;
	}
	return ans;
}

ll Lucas(ll n, ll m)
{
	if(m == 0) return 1;
	return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}

int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--){
		ans=1;
		ll n,m;
		cin>>n>>m;
		cout<<Lucas(n,m)<<"\n";
	}
	return 0;
}
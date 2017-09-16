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
const int mod = 1e9+7; 
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
ll Zi[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int p,q,k;
		ll zi = 0,mu = 0;
		cin>>p>>q>>k;
		mu = quick_mod(p,k);
		for(int i=0;i<=k;i+=2)
		{
			Zi[i] = Lucas(k,i) * quick_mod(q,i) * quick_mod(p-q,k-i);
			//cout<<Zi[i]<<endl;
			zi += Zi[i];
		}
		cout<<zi*quick_mod(mu,mod-2)<<endl;
	}
	return 0;
}
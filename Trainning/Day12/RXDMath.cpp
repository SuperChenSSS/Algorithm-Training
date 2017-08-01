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
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const ll mod = (1e9+7);
ll qk_mi(ll a,ll b,ll c)
{
	ll ans = 1;
	a = a % c;
	while(b>0)
	{
		if(b%2==1)
			ans = (ans * a) % c;
		b = b >> 1;
		a = (a * a) % c;
	}
	return ans;
}
int main()
{
	int kas = 0;
	ll n,k;
	while(~scanf("%lld%lld",&n,&k))
	{
		ll ans = 0;
		n = n % mod;
		ans = qk_mi(n,k,mod);
		ans = ans % mod;
		printf("Case #%d: %lld\n",++kas,ans);
	}
	return 0;
}
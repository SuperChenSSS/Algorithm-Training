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

ll Power_mod(ll a, ll b, ll p)
{
	ll res = 1;
	while(b!=0)
	{
		if(b&1) res = (res*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return res;
}
ll Comb(ll a,ll b, ll p)
{
	if(a < b) return 0;
	if(a == b) return 1;
	if(b > a-b) b = a-b;
	ll ans = 1, ca = 1, cb = 1;
	for(ll i=0; i<b; ++i)
	{
		ca = (ca*(a-i))%p;
		cb = (cb*(b-i))%p;
	}
	ans = (ca*Power_mod(cb, p-2, p))%p;
	return ans;
}
ll Lucas(int n, int m, int p)
{
	ll ans = 1;
	while(n && m && ans)
	{
		ans = (ans * Comb(n%p, m%p, p))%p;
		n /= p;
		m /= p;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
        int n , m , ans  = 0 ;
        cin >> n >> m ;
		int ans1 = 0,ans2 = 0;
        int index = Lucas(m , 1 , mod) * Power_mod(m-1 , n , mod) + Lucas(m , m - 1 , mod) * (Power_mod(m - 1 , n , mod)-m+1);
        for(int i = 2; i <= m - 2 ; i ++)
        {
			ans1 = Lucas(m, i, mod) * (Power_mod(i, m, mod) - i) * (Power_mod(i+1, m, mod) - (i+1));
            ans = ans + Lucas(m , i , mod) * (Power_mod(i , n , mod) - i) * (Power_mod(m - i , n , mod) - (m - i));
			if(ans1>ans)
			{
				ans -= ans + 
			}
			else
			{
				ans -= ans1 + 
			}
        }
        cout << ans + index << endl ;
	}
	return 0;
}
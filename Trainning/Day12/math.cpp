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
const ll mod = (1e9+7); 
const int INF = 1000000000;  
const int maxn = 1e6;
bool check[maxn+10];
int prime[maxn+10];
ll mu[maxn+10];
void Moblus()
{
	memset(check,false,sizeof(check));
	mu[1] = 1;
	int tot = 0;
	for(int i=2;i<=maxn;i++)
	{
		if(!check[i])
		{
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>maxn)
				break;
			check[i*prime[j]] = true;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]] = 0;
				break;
			}
			else
				mu[i*prime[j]] = -mu[i];
		}
	}
}
int main()
{
	ll n,k;
	ll ans;
	ll kas = 0;
	while(~scanf("%lld%lld",&n,&k))
	{
		Moblus();
		ans = 0;
		for(ll i=1;i<=pow(n,k);i++)
			ans += (mu[i] * mu[i] * (ll)floor(sqrt(pow(n,k)/i)))%mod;
		printf("Case #%lld: %lld\n",++kas,ans);
	}
	return 0;
}
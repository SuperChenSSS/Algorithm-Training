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
const int mod = (1e9+7); 
int prime[maxn];
bool isprime[maxn];
//返回n以内素数的个数，素数筛法
int numprime(int n)
{
	int p = 0;
	fill(isprime,isprime+n,true);
	isprime[0] = isprime[1] = false;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			prime[p++] = i;
			for(int j=2*i;j<=n;j+=i)
				isprime[j] = false;
		}
	}
	return p;
}
ll pow_mod(ll x,ll n,ll mod)
{
	ll res = 1;
	while(n>0)
	{
		if(n & 1)
			res = res * x % mod;//如果二进制最低位为1，则乘上x^(2^i)
		x = x * x % mod;//将x平方
		n >>= 1;
	}
	return res;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	numprime(maxn);
	int n;
	while(cin>>n&&n)
	{
		bool flag = true;
		if(!isprime[n])//素数筛
		{
			for(int i=2;i<n;i++)
			{
				int tmp = pow_mod(i, n, n);
				if(tmp!=i)//如果不满足条件
				{
					flag = false;
					break;
				}
			}
		}
		else
			flag = false;
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
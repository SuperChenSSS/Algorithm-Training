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
#include <bitset>
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
int prime[maxn];//存储素数
int sprime[maxn];//存储P-1的素因子
bitset<maxn> pri;//结果只有0和1，判断是否是素数
int k;//记录maxn以内的素数个数
int cnt;//记录素因子的个数
void isprime()
{
	pri.set();//将所有的二进制数都标为1
	for(int i=2;i<maxn;i++)
	{
		if(pri[i])
		{
			prime[k++] = i;
			for(int j=i+i;j<maxn;j+=i)
				pri[j] = 0;
		}
	}
}
void Divide(int n)//将n分解为素因子
{
	cnt = 0;
	int t = (int)sqrt(1.0*n);
	for(int i=0;prime[i]<=t;i++)
	{
		if(n%prime[i]==0)
		{
			sprime[cnt++] = prime[i];
			while(n%prime[i]==0)//因为有可能有多个prime[i]
				n /= prime[i];
		}
	}
	if(n>1)
		sprime[cnt++] = n;//可能只有自己一个素因子
}
ll fast_mod(ll a,ll b,int mod)//快速幂取余
{
	ll res = 1;
	while(b>0)
	{
		a = a % mod;
		if(b&1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	ll P;
	isprime();
	while(cin>>P)
	{
		Divide(P-1);
		for(int g=2;g<P;g++)
		{
			int flag = 1;
			for(int i=0;i<cnt;i++)
			{
				int t = (P-1) / sprime[i];
				if(fast_mod(g, t, P)==1)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				int root = g;
				cout<<root<<endl;
				break;//去掉break的话是求所有的原根
			}
		}
	}
	return 0;
}
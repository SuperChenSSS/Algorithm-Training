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
//返回n以内素数的个数
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
//判定一个数是否是素数
bool is_prime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n % i == 0)
			return false;
		return n != 1;
	}
}
//约数枚举O(sqrt(n))
vector<int> divisor(int n)
{
	vector<int> res;
	for(int i=1;i*i<=n;i++)
	{
		if(n % i == 0)
		{
			res.push_back(i);
			if(i!=n/i)
				res.push_back(n/i);
		}
	}
	return res;
}
//整数分解O(sqrt(n))
map<int,int> prime_factor(int n)
{
	map<int,int> res;
	for(int i=2;i*i<=n;i++)
	{
		while(n % i == 0)
		{
			++res[i];
			n /= i;
		}
	}
	if(n!=1)
		res[n] = 1;
	return res;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		memset(isprime,0,sizeof(isprime));
		memset(prime,0,sizeof(prime));
		if(is_prime(n))
			cout<<"YES\n";
		else
			cout<<"NO\n";
		cout<<"Num:"<<numprime(n)<<endl;
	}
	return 0;
}
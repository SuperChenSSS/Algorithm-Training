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
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		memset(isprime,0,sizeof(isprime));
		memset(prime,0,sizeof(prime));
		cout<<"Num:"<<numprime(n)<<endl;
	}
	return 0;
}
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
//素数筛选：查找出小于等于maxn的素数
//prime[0]存素数的个数
int prime[maxn];
void getPrime()
{
	memset(prime,0,sizeof(prime));
	for(int i=2;i<=maxn;i++)
	{
		if(!prime[i])
			prime[++prime[0]] = i;
		for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
		{
			prime[prime[j]*i] = 1;
			if(i%prime[j]==0)
				break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	getPrime();
	while(cin>>n)
	{
		int flag = 0;
		for(int i=1;i<=n;i++)
		{
			if(prime[i]>=n)
			{
				flag = i;
				break;
			}
		}
		for(int i=1;i<=flag;i++)
		{
			if(prime[i]>=flag)
			{
				flag = i;
				break;
			}
		}
		cout<<prime[prime[flag]]<<"\n";
	}
	return 0;
}
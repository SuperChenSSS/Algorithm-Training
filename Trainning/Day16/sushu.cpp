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
int visit[maxn/32+50];
unsigned int data[5800000];
int prime[5800000],np = 0;

void Prime()//筛素数，数组从0开始
{
	prime[0] = data[0] = 2;
	np = 1;
	for(int i=3;i<maxn;i+=2)//扫所有素数
		if(!visit[i/32] & (1 << ((i/2)%16)))
		{
			prime[np] = i;
			data[np] = data[np-1] * i;//预处理
			np++;
			for(int j=3*i;j<maxn;j+=2*i)//改成i*i会超int范围
				visit[j/32] |= (1 << ((j/2)%16));
		}
}

unsigned int Deal(int n)
{
	int p = upper_bound(prime, prime+np, n) - prime - 1;//定位比n小的第一个素数
	unsigned int ans = data[p];
	for(int i=0;i<np && prime[i]*prime[i]<=n;i++)//此时prime[i]最多10^4
	{
		//扫所有素数的整数次幂
		int mul = prime[i];
		int tmp = prime[i] * prime[i];
		while(tmp/mul == prime[i] && tmp<=n)//防止int越界
		{
			tmp *= prime[i];
			mul *= prime[i];
		}
		ans *= (mul/prime[i]);
	}
	return ans;
}
int main()
{
	int t,n;
	cin>>t;
	Prime();
	for(int kas=1;kas<=t;kas++)
	{
		cin>>n;
		printf("Case %d: %u\n",kas,Deal(n));
	}
	return 0;
}
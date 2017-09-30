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
bool isprime[maxn],isprimesmall[maxn];
//对区间[a,b)内的整数执行筛法,isprime[i-a]=true，i是素数
void Numprime(ll a,ll b)
{
	fill(isprimesmall,isprimesmall+b,true);
	fill(isprime,isprime+b-a,true);
	for(int i=2;(ll)i*i<b;i++)
	{
		if(isprimesmall[i])
		{
			for(int j=2*i;(ll)j*j<b;j+=i)//筛[2,sqrt(b))
				isprimesmall[j] = false;
			for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i)//筛[a,b)
				isprime[j-a] = true;
		}
	}
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	return 0;
}
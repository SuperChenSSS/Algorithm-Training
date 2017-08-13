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
typedef unsigned long long ull;
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7);
bool judge(ll x)
{
	if(x>=1 && x<=9)
		return true;
	ll tmp = x;
	while(x/10)
	{
		if(x % 10 != 0 && tmp % (x % 10) != 0)
			return false;
		x /= 10;
	}
	return true;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	ll t,x,y;
	cin>>t;
	while(t--)
	{
		ll num = 0;
		cin>>x>>y;
		for(ll i=x;i<=y;i++)
			if(judge(i))
				num++;
		cout<<num<<"\n";
	}
	return 0;
}
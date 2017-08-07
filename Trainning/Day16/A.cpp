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
const ll mod = pow(2,32); 
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	ll t,n,ans,kas = 0;
	cin>>t;
	while(t--)
	{
		ll yueshu=0,tmp=0;
		ans = 1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			tmp = i;
			yueshu = gcd(ans,tmp);
			//cout<<yueshu<<" "<<tmp<<" "<<ans<<"\n";
			ans = (tmp / yueshu  * ans + mod) % mod;
		}
		printf("Case %lld: %lld\n",++kas,ans);
	}
	return 0;
}
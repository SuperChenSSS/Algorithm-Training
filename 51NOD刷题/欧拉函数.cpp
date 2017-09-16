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
//欧拉函数的求法：如果a1,a2,a3……是n的质因子数，那么
//m=n*(1-1/a1)*(1-1/a2)*(1-1/a3)…… 

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	while(cin>>n)
	{
		ll ans = n;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				ans = ans * (i-1) / i;
				while(n%i==0)
					n /= i;
			}
		}
		if(n!=1)
			ans = ans * (n-1) / n;
		cout<<ans<<endl;
	}
	return 0;
}
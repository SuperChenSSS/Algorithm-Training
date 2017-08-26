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
  
int main(void)  
{  
	int t, ca = 1;  
	cin >> t;  
	while(t--)  
	{  
		ll n, l = 0, r = 2e9, ans;  
		cin>>n;  
		while(l <= r)  
		{  
			ll mid = (l+r)/2;  
			ll sum = (1+mid)*mid/2;  
			if(sum <= n) 
			{
				ans = sum;
				l = mid+1;  
			}
			else 
				r = mid-1;  
		}  
		printf("Case #%d: %lld\n", ca++, ans);  
	}  
	return 0;  
}  
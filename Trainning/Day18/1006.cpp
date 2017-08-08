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

int main()
{
	ios::sync_with_stdio(false);
	ll n,m;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(m>n*(n-1)/2)
			m = n * (n-1) / 2;
		ll res = 0;
		if(m>=n-1)
			res = 2*n*n - 2*n - 2*m;
		else
			res = 2*m*m + (n+m)*n*(n-m-1);
		cout<<res<<"\n";
	}
	return 0;
}
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
ll gcd(ll a,ll b)
{
	return a % b ? gcd(b,a%b):b;
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
int main()
{
	ios::sync_with_stdio(false);
	ll a,b;
	while(cin>>a>>b)
	{
		cout<<gcd(a,b)<<endl;
		cout<<lcm(a,b)<<endl;
	}
	return 0;
}
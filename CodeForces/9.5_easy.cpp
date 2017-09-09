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

int main()
{
	ios::sync_with_stdio(false);
	ll n,k,t;
	while(cin>>n>>k>>t)
	{
		if(t>=1&&t<=k)
			cout<<t<<endl;
		else if(t>k&&t<=n)
			cout<<k<<endl;
		else if(t>=n+1&&t<=n+k)
			cout<<k-(t-n)<<endl;
	}
	return 0;
}
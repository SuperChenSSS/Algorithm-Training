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
ll arr[maxn];
ll dp[maxn];
int main()
{
	//freopen("1081.txt","r",stdin);
	ios::sync_with_stdio(false);
	ll n,q,ival,lval,sum;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		dp[i] = dp[i-1] + arr[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>ival>>lval;
		cout<<dp[lval+ival-1] - dp[ival-1]<<endl;
	}
	return 0;
}
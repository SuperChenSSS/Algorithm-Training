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
//约瑟夫环：f(x)=(f(x-1)+k)%i;
int main()
{
	ios::sync_with_stdio(false);
	int ans,n,k;
	while(cin>>n>>k)
	{
		ans = 0;
		for(int i=2;i<=n;i++)
			ans = (ans + k) % i;
		cout<<ans+1<<"\n";
	}
	return 0;
}
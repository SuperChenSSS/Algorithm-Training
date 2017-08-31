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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ios::sync_with_stdio(false);
	ll summax,sum;
	int n,num;
	while(cin>>n)
	{
		summax = 0,sum = 0;
		for(int i=0;i<n;i++)
		{
			cin>>num;
			sum = max(sum,0) + num;
			summax = max(sum,summax);
		}
		cout<<summax<<endl;
	}
	return 0;
}
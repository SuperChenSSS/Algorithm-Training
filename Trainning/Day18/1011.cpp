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
int arr[maxn];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		sort(arr+1,arr+1+n);
		int ans = 1;
		for (int i=n;i>1;i--)
		{
			if ((arr[i]-arr[i-1])<=m)
				ans++; 
			else 
				break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}


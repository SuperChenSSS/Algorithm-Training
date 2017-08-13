//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
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
int arr[maxn],vis[maxn];

int main()
{
	int n;
	ll ans;
	while(cin>>n)
	{
		ans = 0;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
		{
			if(arr[i]<vis[i])
			{
				tmp = arr[i];
				arr[i] = vis[i];
				vis[i] = tmp;
			}
			memset(vis,0,sizeof(vis));
		}
		
	}
	return 0;
}
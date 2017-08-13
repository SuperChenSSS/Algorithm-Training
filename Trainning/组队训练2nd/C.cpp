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
const int maxn = 20;
ll arr[maxn];
bool dp[maxn];
int main()
{
	int n;
	ll res;
	while(cin>>n)
	{
		memset(dp,false,sizeof(dp));
		res = 0;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		if(n<3)
		{
			res = 0;
		}
		if(n==3)
		{
			sort(arr,arr+n);
			if(arr[0]+arr[1]>arr[2])
				res++;
		}
		if(n>3)
		{
			sort(arr,arr+n);
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					for(int k=j+1;k<n;k++)
					{
						if(arr[i]+arr[j]>arr[k] && !dp[i] && !dp[j] && !dp[k])
						{
							res++;
							dp[i] = dp[j] = dp[k] = true;
						}												
					}
		}
		cout<<res<<"\n";
	}	
	return 0;
}
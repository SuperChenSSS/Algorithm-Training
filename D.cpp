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
int arr[maxn];
int dp[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,t,left,right;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		int sum = 0;
		cin>>left>>right;
		for(int i=left;i<=right;i++)
			++dp[arr[i]];	
		for(int i=1;i<=maxn-1;i++){
			if(dp[i]==0)
				continue;
			sum += dp[i] * dp[i] * i;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
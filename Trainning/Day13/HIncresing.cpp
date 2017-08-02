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
const int mod = 1000000007; 
const int maxn = (1e5+10);
ll a[maxn],b[maxn];
int Search(int num,int low,int high)
{
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(num>=b[mid])
			low = mid + 1;
		else
			high = mid -1;
	}
	return low;
}
int DP(int n)
{
	int i,len,pos;
	b[1] = a[1];
	len = 1;
	for(i=2;i<=n;i++)
	{
		if(a[i]>=b[len])
		{
			len = len + 1;
			b[len] = a[i];
		}
		else
		{
			pos = Search(a[i],1,len);
			b[pos] = a[i];
		}
	}
	return len;
}
int main()
{
	int t,n;
	cin>>t;
	ll sum;
	while(t--)
	{
		sum = 0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans = DP(n);
		cout<<ans<<"\n";
	}
	return 0;
}
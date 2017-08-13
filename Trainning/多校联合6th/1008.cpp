//@Team: TDteam01
//@Author: CMY
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
const int maxn = 6000;
const int mod = (1e9+7); 
char arr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		ll dis = 0;
		cin>>m;
		cin>>arr;
		int len = strlen(arr);
		int result = 0;
		for(int mid=0;mid<len;mid++)
		{
			int eoff = 1;
			int soff = 1;
			ll nowm = 0;
			while(1)
			{
				if(mid-soff<0 || mid+soff>=len)
					break;
				nowm += abs(arr[mid-soff] - arr[mid+soff]);
				soff++;
				while(nowm>m)
				{
					nowm -= abs(arr[mid-eoff] - arr[mid+eoff]);
					eoff++;
				}
				if(nowm<=m)
					result = max(result,soff-eoff);
			}
		}
		for(int mid=0;mid<len-1;mid++)
		{
			int eoff = 1;
			int soff = 1;
			ll nowm = 0;
			while(1)
			{
				if(mid-soff+1<0 || mid+soff>=len)
					break;
				nowm += abs(arr[mid-soff+1] - arr[mid+soff]);
				soff++;
				while(nowm>m)
				{
					nowm -= abs(arr[mid-eoff+1] - arr[mid+eoff]);
					eoff++;
				}
				if(nowm<=m)
					result = max(result,soff-eoff);
			}
		}
		cout<<result<<"\n";
	}
	return 0;
}
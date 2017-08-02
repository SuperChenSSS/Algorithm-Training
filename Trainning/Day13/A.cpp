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
const ll maxn = 1e6;
const ll maxm = pow(2,31);
ll arr[maxn];
double result[maxm];
int main()
{
	//ios::sync_with_stdio(false);
	int n;
	while(~scanf("%d",&n) && n!=0)
	{
		int res = 0;
		memset(arr,0,sizeof(arr));
		memset(result,0,sizeof(result));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			result[arr[i]]++;
			//cout<<arr[i]<<result[arr[i]]<<"\n";
		}
		sort(arr,arr+n);
		//cout<<arr[n]<<"\n";
		for(ll i=0;i<=arr[n-1];i++)
		{
			//cout<<arr[i]<<" "<<result[i]<<"\n";
			if(result[i]==1)
			{
				res = i;
				break;
			}
		}
		printf("%d\n",res);
		//cout<<res<<"\n";
	}
	return 0;
}
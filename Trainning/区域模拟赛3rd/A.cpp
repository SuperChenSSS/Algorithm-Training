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
const int maxn = 1e6;
const int mod = (1e9+7); 
ll arr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		bool stat[n+5] = {false},chong[n+5] = {false};
		for(int i=1;i<=m;i++){
			cin>>arr[i];
			stat[arr[i]] = true;
		}
		for(int i=m;i>=1;i--){
			if(!chong[arr[i]]){
				cout<<arr[i]<<"\n";
				chong[arr[i]] = true;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(stat[i]==false)
				cout<<i<<"\n";
		}
	}
	return 0;
}
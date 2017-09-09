#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
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
	freopen("95.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		memset(arr,0,sizeof(arr));
		ll sum = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			//printf("%lld %lld\n",arr[i-1],arr[i]);
			if(arr[i-1]==1&&arr[i]==0)
				continue;
			else
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
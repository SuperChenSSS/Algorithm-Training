#include <iostream> 
#include <cstdio>  
#include <cstring>  
#include <algorithm>   
#include <string>  
#include <vector>  
#include <cmath>  
#include <queue> 
using namespace std;  
typedef long long ll;     
const int INF = 1e9;  
const int maxn = 1e6;
const int mod = (1e9+7); 
bool cmp(int i,int j)
{
	return i>j;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	ll n,arr[35];
	while(cin>>n)
	{
		ll sum = 0;
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		arr[0] = 1;
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n;i++)
			arr[i] = arr[i] * arr[i-1];
		for(int i=0;i<=n;i++)
			sum += arr[i];
		cout<<sum<<endl;
	}
	return 0;
}
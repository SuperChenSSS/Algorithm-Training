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
bool state[maxn];
ll x;
int main()
{
	//freopen("4.txt","r",stdin);
	ios::sync_with_stdio(false);
	ll m,n;
	while(cin>>n>>m)
	{
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
			cin>>arr[i];
		while(m--)
		{
			memset(state,false,sizeof(state));
			cin>>x;
			for(int i=0;i<n;i++)
			{
				arr[i] ^= x;
				state[arr[i]] = true;
			}
			sort(arr,arr+n);
			/*for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
			cout<<"\n";*/
			if(arr[0]!=0)
			{
				cout<<0<<endl;	
			}
			else
			{
				for(int i=1;i<n;i++)
					if(arr[i]-arr[i-1]!=1)
					{
						cout<<arr[i-1]+1<<endl;
						break;
					}
			}
		}
	}
	return 0;
}
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
ll mi[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		mi[0] = 1;
		for(int i=1;i<n;i++)
			mi[i] = mi[i-1] * 2;
		//m = m % (ll)pow(2,n-1);
		//cout<<m<<"\n";
		for(int j=0;j<m;j++)	
			for(int i=1;i<n;i++)
			{
				arr[i] = arr[i] ^ arr[i-1];
			}
		for(int i=0;i<n;i++)
		{
			if(i!=n-1)
				cout<<arr[i]<<" ";
			else
				cout<<arr[i]<<"\n";
		}
	}
	return 0;
}
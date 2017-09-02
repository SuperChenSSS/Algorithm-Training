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
ll a[maxn],b[maxn];
int main()
{
	freopen("51.txt","r",stdin);
	ios::sync_with_stdio(false);
	ll n,num;
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		num = 0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];	
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				//cout<<a[i-1]<<" "<<b[j+1]<<endl;
				if(i-1<0&&j+1>n)
					continue;
				if(a[i]==b[j] && a[i-1]==b[j+1])
					num++;
			}
		//cout<<num<<endl;
		cout<<(ll)pow(2,num-1)<<endl;	
	}
	return 0;
}
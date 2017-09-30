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
struct arr
{
	int from,to,ren,xiao;
}arr[maxn];
int xiao[maxn];
bool cmp(struct arr a,struct arr b)
{
	if(a.to)
	return false;
}
int main()
{
	freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n && n!=0)
	{
		int tmp = 0,xia = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i].from>>arr[i].to>>arr[i].ren;
			arr[i].xiao = arr[i].ren;
		}
		sort(arr,arr+n,cmp);
		for(int i=0;i<n;i++)
		{
			tmp = arr[i].to;
			for(int j=i+1;j<n;j++)
			{
				if(arr[j].from<tmp)
					arr[i].xiao += arr[j].ren;
				else
					break;
			}
		}
		for(int i=0;i<n;i++)
			xia = max(xia,arr[i].xiao);
		cout<<xia<<endl;
	}
	if(n==0)
		cout<<"*"<<endl;
	return 0;
}
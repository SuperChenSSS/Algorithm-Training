//TDteam01
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
struct node
{
	int val,pos;
	node()
	{
		val = pos = 0;
	}
}arr[maxn];
int cmp(node a,node b)
{
	return a.val>b.val;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,maxm = 0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].val;
			arr[i].pos = i;
		}
		sort(arr+1,arr+1+n,cmp);
		bool judge =  true;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(arr[j].pos % i != 0)
				{
					if(judge)
					{
						cout<<arr[j].val;
						judge = false;
					}
					else
						cout<<" "<<arr[j].val;
					break;
				}
		cout<<"\n";
	}
	return 0;
}
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
const int mod = (1e9+7); 
const int MAXN = 1e4;
#define typec int
bool vis[MAXN];
int pre[MAXN];
int Lowcost[MAXN],s[MAXN],t[MAXN],l[MAXN],Cost[MAXN][MAXN];
void Dijkstra(typec cost[][MAXN],typec lowcost[],int n,int beg)
{
	for(int i=0; i<n; i++)
	{
		lowcost[i]=INF;
		vis[i]=false;
		pre[i]=-1;
	}
	lowcost[beg]=0;
	for(int j=0; j<n; j++)
	{
		int k=-1;
		int Min=INF;
		for(int i=0; i<n; i++)
			if(!vis[i]&&lowcost[i]>Min)
			{
				Min=lowcost[i];
				k=i;
			}
		if(k==-1)break;
		vis[k]=true;
		for(int i=0; i<n; i++)
			if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i])
			{
				lowcost[i]=lowcost[k]+cost[k][i];
				pre[i]=k;
			}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int res = 0;
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>s[i]>>t[i]>>l[i];
			Cost[s[i]][t[i]] = l[i];
		}
		ll minm = INF;
		for(int j=0;j<n;j++){
			Dijkstra(Cost,Lowcost,n,j);
			sort(Lowcost,Lowcost+n);
			if(minm>Lowcost[n-1])
			{
				minm = Lowcost[n-1];	
			}
		}
		cout<<minm<<endl;
	}
	return 0;
}
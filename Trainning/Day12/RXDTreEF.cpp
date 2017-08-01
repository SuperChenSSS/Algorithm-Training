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
const int maxn = 1e6;
int remin(int a,int b)
{
	if(a<b)return a;
	else return b;
}
struct Edge
{
	int to;
	int next;
	int cost;
}edge[2000005];
struct Node
{
	int road;
	int s;
}node[1000005];
int head[1000005],tot,father[1000005],k;
long long ans;
void addedge(int u,int v,int cost)
{
	edge[tot].cost=cost;edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void dfsroad(int u)
{
	int i;
	for(i = head[u];i != -1;i = edge[i].next)
	{
		int v=edge[i].to;
		if(father[v]!=0)continue;
		father[v]=u;
		node[v].road=node[u].road+edge[i].cost;
		dfsroad(v);
	}
	return;

}
int dfsson(int u)
{
	int i,son;
	son=1;
	for(i = head[u];i != -1;i = edge[i].next)
	{
		int v=edge[i].to;
		if(father[v]==u)son=son+dfsson(v);
	}
	return node[u].s=son;

}
int dfsans(int u)
{
	int i;
	for(i = head[u];i != -1;i = edge[i].next)
	{
		int v=edge[i].to;
		if(father[v]==u)
		{
			ans=ans+(long long)(remin(k,node[v].s))*(long long)(edge[i].cost);
			dfsans(v);
		}
	}
}
bool cmp(Node a,Node b)
{
	if(a.road>b.road)return false;
	else return true;
}
int main()
{
	int n,i,a,b,c,numedge,now,rest;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
	memset(head,-1,sizeof(head));
	memset(father,0,sizeof(father));
	numedge=0;tot=0;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
		addedge(b,a,c);
	}
	node[1].road=0;
	father[1]=1;
	dfsroad(1);
	dfsson(1);
	ans=0;
	dfsans(1);
	printf("%lld\n",ans);
	}
	return 0;
}
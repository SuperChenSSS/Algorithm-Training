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
struct qnode
{
	int v,c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){}
	bool operator <(const qnode &r)const
	{
		return c>r.c;
	}
};
struct Edge
{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
bool vis[maxn];
int dist[maxn];
void Dij(int n,int start)//点的编号从1开始
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dist[i] = INF;
	priority_queue<qnode> que;
	dist[start] = 0;
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty())
	{
		tmp = que.top();
		que.pop();
		int u = tmp.v;
		if(vis[u])
			continue;
		vis[u] = true;
		for(int i=0;i<E[u].size();i++)
		{
			int v = E[tmp.v][i].v;
			int cost = E[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost)
			{
				dist[v] = dist[u] + cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}
void addedge(int u,int v,int w)
{
	E[u].push_back(Edge(v,w));
}
int main()
{
	ios::sync_with_stdio(false);
	int n,from,to,len;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>from>>to>>len;
		addedge(from, to, len);
	}
	Dij(n,1);
	for(int i=1;i<n-1;i++)
		cout<<dist[i]<<endl;
	return 0;
}
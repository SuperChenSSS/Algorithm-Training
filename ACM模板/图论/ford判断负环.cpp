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
int dist[maxn];
struct Edge
{
	int u,v;
	int cost;
	Edge(int _u=0,int _v=0,int _cost=0):u(_u),v(_v),cost(_cost){}
};
vector<Edge> E;
bool bellman_ford(int start,int n)//点的编号从1开始
{
	for(int i=1;i<=n;i++)
		dist[i] = INF;
	dist[start] = 0;
	for(int i=1;i<n;i++)//最多做n-1次
	{
		bool flag = false;
		for(int j=0;j<E.size();j++)
		{
			int u = E[j].u;
			int v = E[j].v;
			int cost = E[j].cost;
			if(dist[v]>dist[u]+cost)
			{
				dist[v] = dist[u] + cost;
				flag = true;
			}
		}
		if(!flag)
			return true;//没有负环回路
	}
	for(int j=0;j<E.size();j++)
		if(dist[E[j].v]>dist[E[j].u]+E[j].cost)
			return false;//有负环回路
	return true;//没有负环回路
}
void addedge(int u,int v,int w)
{
	E.push_back(Edge(u,v,w));
}
int main()
{
	ios::sync_with_stdio(false);
	int n,from,to,len;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>from>>to>>len;
		addedge(from,to,len);
	}
	bool flag = bellman_ford(1, n);
	if(flag)
		cout<<"没有负环\n";
	else
		cout<<"有负环\n";
	for(int i=1;i<n-1;i++)
		cout<<dist[i]<<endl;
	return 0;
}
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
	int v,cost1,cost2;
	Edge(int _v=0,int _cost1=0,int _cost2=0):v(_v),cost1(_cost1),cost2(_cost2){}
};
vector<Edge> E[maxn];
bool vis[maxn];
int distT[maxn],distF[maxn];
void Dij(int n,int start)//点的编号从1开始
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		distT[i] = INF;
		distF[i] = INF;
	}
		
	priority_queue<qnode> que;
	distT[start] = 0;
	distF[start] = 0;
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
			int costT = E[u][i].cost1;
			int costF = E[u][i].cost2;
			if(!vis[v]&&distF[v]>distF[u]+costF)
			{
				distF[v] = distF[u] + costF;
				distT[v] = distT[u] + costT;
				que.push(qnode(v,distF[v]));
				que.push(qnode(v,distT[v]));
			}
		}
	}
}
void addedge(int u,int v,int cost1,int cost2)
{
	E[u].push_back(Edge(v,cost1,cost2));
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(distT,0,sizeof(distT));
		memset(distF,0,sizeof(distF));
		memset(E,0,sizeof(E));
		int n,m1,m2,from,to,len,L;
		cin>>n>>m1>>m2>>L;
		for(int i=0;i<m1;i++)//不淋雨，代价为0
		{
			cin>>from>>to;
			addedge(from,to,1,0);
		}
		for(int i=0;i<m2;i++)//淋雨，代价为len
		{
			cin>>from>>to>>len;
			addedge(from,to,len,len);
		}
		Dij(n,1);
		/*for(int i=2;i<n+1;i++)
			cout<<distF[i]<<endl;*/
		//cout<<distF[n]<<" "<<distT[n]<<endl;
		if(distF[n]&&distT[n]<=L)
			cout<<distF[n]<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
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
struct edge
{
	int to,cost;
 	edge(int _to,int _cost){to = _to;cost = _cost;}
};
typedef pair<int,int> P;//first是最短距离，second是顶点的编号
int V;//顶点数
vector<edge> G[maxn];
int d[maxn];
void Dij(int s)
{//通过指定greater<P>参数，堆按照first从小到大的顺序取出值
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+V,INF);
	d[s] = 0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p = que.top();que.pop();
		int v = p.second;
		if(d[v]<p.first)	continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge e = G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
void addedge(int u,int v,int w)
{
	G[u].push_back(edge(v,w));
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	return 0;
}
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
const int maxn = 1e3;
const int mod = (1e9+7); 
//最短路径还原
int E,V;
int prv[maxn];//最短路上的前驱结点
int cost[maxn][maxn];
bool used[maxn];
int d[maxn];
//求从起点s出发到各个顶点的最短距离
int addedge(int u,int v,int w)
{
	cost[u][v] = w;
}
void Dij(int s)
{
	s--;
	fill(d,d+V,INF);
	fill(used,used+V,false);
	fill(prv,prv+V,-1);
	d[s] = 0;
	while(true)
	{
		int v = -1;
		for(int u=0;u<V;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v = u;
		if(v==-1)	break;
		used[v] = true;
		for(int u=0;u<V;u++)
			if(d[u]>d[v]+cost[v][u])
			{
				d[u] = d[v] + cost[v][u];
				prv[u] = v;
			}
	}
}
//到顶点t的最短路
vector<int> get_path(int t)
{
	t--;
	vector<int> path;
	for(;t!=-1;t=prv[t])
		path.push_back(t);//不断沿着prv[t]走直到t=s
	reverse(path.begin(),path.end());
	return path;
}
int main()
{
	freopen("dij.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>V>>E)
	{
		for(int i=0;i<E;i++)
		{
			int u,v,tmp;
			cin>>u>>v>>tmp;
			u--;v--;
			addedge(u, v, tmp);
		}
		vector<int> least;
		vector<int>::iterator ite;
		Dij(1);
		for(int i=0;i<V;i++)
			cout<<d[i]<<" ";
		cout<<endl;
		least = get_path(3);
		for(ite=least.begin();ite!=least.end();++ite)
			cout<<*ite+1<<" ";
		cout<<endl;
	}
	return 0;
}
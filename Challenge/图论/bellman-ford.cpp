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
//最短路问题:Bellman-Ford
struct edge{int from,to,cost;};
edge es[maxn];//边
int d[maxn];//最短距离
int V,E;//V顶点数，E边数
//求解从顶点s出发到所有点的最短距离
void shortest_path(int s)
{
	for(int i=0;i<V;i++)
		d[i] = INF;
	d[s] = 0;
	while(true)
	{
		bool update = false;
		for(int i=0;i<E;i++)
		{
			edge e = es[i];
			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update)	break;
	}
}
//判断是不是负图
bool find_negative_loop()
{
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++)
		for(int j=0;j<E;j++)
		{
			edge e = es[j];
			if(d[e.to]>d[e.from]+e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				//如果第n次仍然更新了，则存在负圈
				if(i==V-1)
					return true;
			}
		}
	return false;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	return 0;
}
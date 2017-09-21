#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <Map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
int Map[505][505],v[505],dis[505],n,m,End,start,score[505],ans[505];
void Dij(int x)
{
	ans[x] = score[x];//ans[i]从起始点到i所获得得分
	memset(v,0,sizeof(v));
	for(int i=0;i<n;i++)//更新该节点连的边
	{
		if(Map[x][i]<INF)
			ans[i] = ans[x] + score[i];
		dis[i] = Map[x][i];
	}
	dis[x] = 0;
	v[x] = 1;//设为已访问
	for(int i=1;i<n;i++)//寻找最短路径
	{
		int u = 0,min = INF;
		for(int j=0;j<n;j++)//找到距离当前访问的点最近的点
		{
			if(!v[j]&&dis[j]<min)
			{
				min = dis[j];
				u = j;
			}
		}
		v[u] = 1;//访问该点
		for(int k=0;k<n;k++)//更新距离和分数
		{
			if(!v[k]&&dis[k]>Map[u][k]+dis[u])
			{
				dis[k] = Map[u][k] + dis[u];
				ans[k] = ans[u] + score[k];
			}
		}
		for(int k=0;k<n;k++)
		{
			if(dis[k]==Map[u][k]+dis[u])
				ans[k] = max(ans[k],ans[u]+score[k]);//若路程相同，找出得分最大的
		}
	}
	cout<<dis[End]<<" "<<ans[End]<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	int x,y,z;
	cin>>n>>m>>start>>End;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			Map[i][j] = INF;
	for(int i=0;i<n;i++)
		cin>>score[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		Map[x][y] = Map[y][x] = z;
	}
	Dij(start);
	return 0;
}
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
const int maxn = 1100;
//SAP邻接矩阵形式
//结点编号从0开始
int maze[maxn][maxn];
int gap[maxn],dis[maxn],pre[maxn],cur[maxn];
int sap(int start,int end,int nodenum)
{
	memset(cur,0,sizeof(cur));
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	int u = pre[start] = start,maxflow = 0,aug = -1;
	gap[0] = nodenum;
	while(dis[start]<nodenum)
	{
		loop:
			for(int v=cur[u];v<nodenum;v++)
				if(maze[u][v] && dis[u]==dis[v]+1)
				{
					if(aug==-1 || aug>maze[u][v])
						aug = maze[u][v];
					pre[v] = u;
					u = cur[u] = v;
					if(v==end)
					{
						maxflow += aug;
						for(u=pre[u];v!=start;v=u,u=pre[u])
						{
							maze[u][v] -= aug;
							maze[v][u] += aug; 
						}
						aug -= 1;
					}
					goto loop;
				}
			int mindis = nodenum-1;
			for(int v=0;v<nodenum;v++)
				if(maze[u][v] && mindis>dis[v])
				{
					cur[u] = v;
					mindis = dis[v];
				}
			if((--gap[dis[u]])==0)	break;
			gap[dis[u]=mindis+1]++;
			u = pre[u];
	}
	return maxflow;
}
int main()
{
	
	return 0;
}
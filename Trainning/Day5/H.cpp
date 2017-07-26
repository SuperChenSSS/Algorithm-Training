#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
/* ***********************************************************
//二分图匹配（匈牙利算法的DFS实现）(邻接矩阵形式)
//初始化：g[][]两边顶点的划分情况
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配
//g没有边相连则初始化为0
//uN是匹配左边的顶点数，vN是匹配右边的顶点数
//调用：res=hungary();输出最大匹配数
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解
//时间复杂度:O(VE)
*************************************************************/
//顶点编号从0开始的
const int maxn = 510;
int un,vn;//u,v的数目，使用前必须赋值
int g[maxn][maxn];//邻接矩阵
int linker[maxn];
bool used[maxn];
bool dfs(int u)
{
	for(int v=0;v<vn;v++)
		if(g[u][v] && !used[v])
		{
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
		return false;
}
int hungary()
{
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<un;u++)
	{
		memset(used,false,sizeof(used));
		if(dfs(u))	res++;
	}
	return res;
}
int main()
{
	while(cin>>un>>vn)
	{
		memset(g,0,sizeof(g));
		for(int i=0;i<un;i++)
		{
			int num,posm[300];
			cin>>num;
			for(int j=0;j<num;j++)
				{
					cin>>posm[j];
					posm[j]--;
					g[i][posm[j]] = 1;
				}
		}
		cout<<hungary()<<"\n";
	}
	return 0;
}
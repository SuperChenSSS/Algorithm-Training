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
//顶点编号从0开始的
const int MAXN = 510;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
	for(int v = 0; v < vN;v++)
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
	for(int u = 0;u < uN;u++)
	{
		memset(used,false,sizeof(used));
		if(dfs(u))
			res++;
	}
	return res;
}

int main()
{
	//freopen("2.txt","r",stdin);
	ios::sync_with_stdio(false);
	int m,n,x,y;
	cin>>m>>n;
	uN = m;
	vN = n;
	while(cin>>x>>y&&(x!=-1||y!=-1))
	{
		g[x][y] = 1;
	}
	int result = hungary();
	if(result)
		cout<<result+1<<"\n";
	else
		cout<<"No Solution!\n";
	return 0;
}
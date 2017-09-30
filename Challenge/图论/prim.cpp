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
//Prim算法
int cost[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int V;
int prim()
{
	for(int i=0;i<V;i++)
	{
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;
	while(true)
	{
		int v = -1;
		//从不属于x的顶点中选取从x到其权值最小的顶点
		for(int u=0;u<V;u++)
			if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
				v = u;
		if(v==-1)
			break;
		used[v] = true;//把顶点v加入x
		res += mincost[v];//把边的长度加到结果里
		for(int u=0;u<V;u++)
			mincost[u] = min(mincost[u],cost[v][u]);	
	}
	return res;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	return 0;
}
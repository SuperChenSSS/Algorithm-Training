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
struct edge{int u,v,cost;};
bool cmp(const edge& e1,const edge& e2)
{
	return e1.cost < e2.cost;
}
//并查集板子
int par[maxn];//父亲
int height[maxn];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i] = i;
		height[i] = 0;
	}
}
//查询树的根
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x] = find(par[x]);
}
//判断x和y是否属于一个集合
bool same(int x,int y)
{
	return find(x) == find(y);
}
//合并x和y所属的集合
void unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return;
	if(height[x]<height[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if(height[x]==height[y])
			height[x]++;
	}
}
edge es[maxn];
int V,E;
int Kru()
{
	sort(es,es+E,cmp);
	init(V);
	int res = 0;
	for(int i=0;i<E;i++)
	{
		edge e = es[i];
		if(!same(e.u,e.v))
		{
			unite(e.u,e.v);
			res += e.cost;
		}
	}
	return res;
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	return 0;
}
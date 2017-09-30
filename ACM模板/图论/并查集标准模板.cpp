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
//并查集板子
int par[maxn];//父亲
int rank[maxn];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i] = i;
		rank[i] = 0;
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
//合并x和y所属的集合
void unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return;
	if(rank[x]<rank[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}
//判断x和y是否属于一个集合
bool same(int x,int y)
{
	return find(x) == find(y);
}
int main()
{
	ios::sync_with_stdio(false);
	
	return 0;
}
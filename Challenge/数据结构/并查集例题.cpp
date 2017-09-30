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
//判断x和y是否属于一个集合
bool same(int x,int y)
{
	return find(x) == find(y);
}
int T[maxn],X[maxn],Y[maxn];
int main()
{
	freopen("bcj.txt","r",stdin);
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++)
		scanf("%d%d%d",&T[i],&X[i],&Y[i]);
	init(3*N);
	int ans = 0;
	for(int i=0;i<K;i++)
	{
		int t = T[i];
		int x = X[i] - 1,y = Y[i] - 1;
		if(x<0||N<=x||y<0||N<=y)
		{
			ans++;
			continue;
		}
		if(t==1)
		{
			if(same(x,y+N)||same(x,y+2*N))
				ans++;
			else
			{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+2*N,y+2*N);
			}
		}
		else
		{
			if(same(x,y)||same(x,y+2*N))
				ans++;
			else
			{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
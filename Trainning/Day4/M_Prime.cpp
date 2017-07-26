#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
//一开始输入的是坐标。按村庄序号排的，然后是m行（a,b）表示的是a,b之间已经有高速公路了。求出还需要建设的公路；
//使得任意两座村庄互通，但是总的距离最短；
//其实就是求最小生成树啊
const int INF = 0x3f3f3f3f;
const int maxn = 110;
const int N = 510;
int map[N][N];
bool vis[maxn];
int lowc[maxn];
int Prim(int cost[][maxn],int n)//点事0~n-1
{
	int ans = 0;
	memset(vis,false,sizeof(vis));
	vis[0] = true;
	for(int i=1;i<n;i++)
		lowc[i] = cost[0][i];
	for(int i=1;i<n;i++)
	{
		int minc = INF;
		int p = -1;
		for(int j=0;j<n;j++)
			if(!vis[j]&&minc>lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		if(minc==INF)
			return -1;//原图不连通
		ans +=  minc;
		vis[p] = true;
		for(int j=0;j<n;j++)
			if(!vis[j]&&lowc[j]>cost[p][j])
				lowc[j] = cost[p][j];
	}
	return ans;
}
int main()
{
	int t,n;
	while(t--)
	{
		cin>>n;
		memset(map,inf,sizeof(map));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>map[i][j];
		int ans = Prim(map, n);
		cout<< ans <<"\n";
	}
	return 0;
}
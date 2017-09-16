/** 
 *1、最小生成树Prim算法(2015.1.1) 
 *2、Kruskal算法 
 */  
#include <iostream>  
#include <cstdio>  
#include <map>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <queue>  
#include <vector>  
#include <stack>  
#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cmath>  
using namespace std;  
const int inf=0x3f3f3f3f;  
int G[1001][1001];//邻接矩阵  
int vis[1001],lowc[1001];  
int prim(int G[][1001],int n)
{  
	int i,j,p,minc,res=0;  
	memset(vis,0,sizeof(vis));  
	vis[1]=1;//从1开始访问  
	for(i=2;i<=n;i++) 
		lowc[i]=G[1][i];  
	for(i=2;i<=n;i++)
	{  
		minc=inf; p=-1;  
		for(j=1;j<=n;j++)
		{  
			if(vis[j]==0&&lowc[j]<minc) 
			{
				minc=lowc[j]; 
				p=j;  
			}  
		}  
		//cout<<minc<<endl;  
		if(inf==minc) 
			return -1;//原图不联通  
		res+=minc; 
		vis[p]=1;  
		for(j=1;j<=n;j++)
		{//更新lowc[]  
			if(vis[j]==0&&lowc[j]>G[p][j])
				lowc[j]=G[p][j];
		}  
	}  
	return res;  
}  
  
int main()  
{  
	int n,m;  
	while(cin>>n>>m){  
		int x,y,w;  
		memset(G,inf,sizeof(G));//首先记录所有边的权为inf  
		for(int i=1;i<=m;i++){  
			cin>>x>>y>>w;  
			G[x][y]=G[y][x]=w;  
		}  
		cout<<prim(G,n)<<endl;  
	}  
	return 0;  
}  
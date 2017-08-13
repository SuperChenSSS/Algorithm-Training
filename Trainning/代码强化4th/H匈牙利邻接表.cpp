#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 5010;
const int maxm = 50010;
struct Edge
{
	int to,next;	
}edge[maxm];
int head[maxn],tot;
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
int linker[maxn];
bool used[maxn];
int un;
bool dfs(int u)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v = edge[i].to;
		if(!used[v])
		{
			used[v] = true;
			if(linker[v]==-1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary()
{
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<un;u++)//点的编号0~un-1
	{
		memset(used,false,sizeof(used));
		if(dfs(u))
			res++;
		return res;
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		init();
		for(int i=0;i<n;i++)
		{
			int num,posm[300],flag[300] = {0};
			cin>>num;
			for(int j=0;j<num;j++)
			{
				cin>>posm[j];
				addedge(i, posm[j]-1);
				flag[posm[j]]++;
				if(flag[posm[j]]>1)
					un++;
			}
		}
		int res = hungary();
		cout<<res<<"\n";
	}
	return 0;
}
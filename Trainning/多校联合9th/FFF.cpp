//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
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
const int mod = (1e9+7); 
/*
* Tarjan算法
* 复杂度O(N+M)
*/

const int MAXN = 20010;//点数
const int MAXM = 50010;//边数
struct Edge
{
	int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~scc
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc
//num数组不一定需要，结合实际情况
void addedge(int u,int v)
{
	edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}

void Tarjan(int u)
{
	int v;
	Low[u] = DFN[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	for(int i = head[u];i != -1;i = edge[i].next)
	{
		v = edge[i].to;
		if( !DFN[v] )
		{
			Tarjan(v);
			if( Low[u] > Low[v] )Low[u] = Low[v];
		}
	else if(Instack[v] && Low[u] > DFN[v])
		Low[u] = DFN[v];
	}
	if(Low[u] == DFN[u])
	{
		scc++;
		do
		{
			v = Stack[--top];
			Instack[v] = false;
			Belong[v] = scc;
			num[scc]++;
		}while( v != u);
	}
}
void solve(int N)
{
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	memset(num,0,sizeof(num));
	Index = scc = top = 0;
	for(int i = 1;i <= N;i++)
		if(!DFN[i])
			Tarjan(i);
}
int point[MAXN];
int pointnum;
bool used[MAXN];
bool xianglian[MAXN][MAXN];
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
	memset(xianglian,false,sizeof(xianglian));
}
void dfs(int root,int u)
{
	int v;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		v = edge[i].to;
		if(!xianglian[root][v])
		{
			xianglian[root][v] = true;
			dfs(root,v);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	int t;
	cin>>t;
	while(t--)
	{
		init();
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			addedge(x,y);
		}
		solve(n);
		if(scc==1)
			cout<<"I love you my love and our love save us!\n";
		else
		{
			pointnum = 0;
			memset(point,0,sizeof(point));
			memset(used,false,sizeof(used));
			for(int i=1;i<=n;i++)
			{
				if(!used[Belong[i]])
				{
					point[++pointnum] = i;
					used[Belong[i]] = true;
				}
			}
			bool ok = true;
			memset(xianglian,false,sizeof(xianglian));
			for(int i=1;i<=pointnum;i++)
				dfs(point[i],point[i]);
			for(int i=1;i<pointnum;i++)
				for(int j=i+1;j<=pointnum;j++)
				{
					if(!ok)
						break;
					if(!xianglian[point[i]][point[j]] && !xianglian[point[j]][point[i]])
					{
						ok = false;
						break;
					}
				}
			if(ok)
				cout<<"I love you my love and our love save us!\n";
			else
				cout<<"Light my fire!\n";
		}
	}
	return 0;
}
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
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
const int maxn = 20020;
const int maxm = 100010;
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
bool vis[maxn];//染色标记，为true表示选择
int S[maxn],top;//栈
bool dfs(int u)
{
	if(vis[u^1])
		return false;
	if(vis[u])
		return true;
	vis[u] = true;
	S[top++] = u;
	for(int i=head[u];i!=-1;i=edge[i].next)
		if(!dfs(edge[i].to))
			return false;
	return true;
}
bool twosat(int n)
{
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i += 2)
	{
		if(vis[i]||vis[i^1])
			continue;
		top = 0;
		if(!dfs(i))
		{
			while(top)	vis[S[--top]] = false;
			if(!dfs(i^1))	return false;
		}
	}
	return true;
}
int main()
{
	int n,m;
	int u,v;
	while(cin>>n>>m)
	{
		init();
		while(m--)
		{
			cin>>u>>v;
			u--;v--;
			addedge(u,v^1);
			addedge(v,u^1);
		}
		if(twosat(2*n))
		{
			for(int i=0;i<2*n;i++)
				if(vis[i])
					cout<<i+1<<"\n";
		}
		else
			cout<<"NIE\n";
	}
	return 0;
}
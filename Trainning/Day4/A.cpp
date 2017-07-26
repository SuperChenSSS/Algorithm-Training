#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 50010;
struct Edge
{
	int to,next;	
}edge[maxn*2];
int head[maxn],tot;
int top[maxn];//top[v]表示v所在的重链的顶端节点
int fa[maxn];//父亲节点
int deep[maxn];//深度
int num[maxn];//num[v]表示以v为根的子树的节点数
int p[maxn];//p[v]表示v对应的位置
int fp[maxn];//fp和p数组相反
int son[maxn];//重儿子
int pos;
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
	pos = 1;//使用树状数组，编号从头1开始
	memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs1(int u,int pre,int d)
{
	deep[u] = d;
	fa[u] = pre;
	num[u] = 1;
	for(int i=head[u];i!=-1;i = edge[i].next)
	{
		int v = edge[i].to;
		if(v!=pre)
		{
			dfs1(v,u,d+1);
			num[u] += num[v];
			if(son[u]==-1||num[v]>num[son[u]])
				son[u] = v;
		}
	}
}
void getpos(int u,int sp)
{
	top[u] = sp;
	p[u] = pos++;
	fp[p[u]] = u;
	if(son[u] == -1)
		return;
	getpos(son[u],sp);
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v = edge[i].to;
		if(v!=son[u]&&v!=fa[u])
			getpos(v,v);
	}
}
//树状数组
int lowbit(int x)
{
	return x&(-x);
}
int c[maxn];
int n;
int sum(int i)
{
	int s = 0;
	while(i>0)
	{
		s += c[i];
		i -= lowbit(i);
	}
	return s;
}
void add(int i,int val)
{
	while(i<=n)
	{
		c[i] += val;
		i += lowbit(i);
	}
}
void Change(int u,int v,int val)//u->v的路径上点的值改变val
{
	int f1 = top[u],f2 = top[v];
	int tmp = 0;
	while(f1!=f2)
	{
		if(deep[f1]<deep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}
		add(p[f1],val);
		add(p[u]+1,-val);
		u = fa[f1];
		f1 = top[u];
	}
	if(deep[u]>deep[v])
		swap(u,v);
	add(p[u],val);
	add(p[v]+1,-val);
}
int a[maxn];
int main()
{
	int M,P;
	while(scanf("%d%d%d",&n,&M,&P) == 3)
	{
		int u,v;
		int C1,C2,K;
		char op[10];
		init();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		while(M--)
		{
			scanf("%d%d" ,&u,&v);
			addedge(u, v);
			addedge(v,u);
		}
		dfs1(1,0,0);
		getpos(1,1);
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			add(p[i],a[i]);
			add(p[i]+1,-a[i]);
		}
		while(P--)
		{
			cin>>op;
			if(op[0] == 'Q')
			{
				scanf("%d",&u);
				printf("%d\n",sum(p[u]));
			}
			else
			{
				scanf(" %d%d%d",&C1,&C2,&K);
				if(op[0]=='D')
					K = -K;
				Change(C1, C2, K);
			}
		}
	}
	return 0;
}
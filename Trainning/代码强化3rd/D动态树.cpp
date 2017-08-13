#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
/*
切割、合并子树，路径上所有点的点权增加一个值，查询路径上点权的最大值
动态维护一组森林，要求支持以下操作：
link(a,b):如果a，b不在同一棵子树中，则通过在a,b之间连边的方式，连接这两棵子树
cut(a,b):如果a,b在同一棵子树中，且a!=b,则将a视为这棵子树的根之后，切断b与其父亲节点的连接
ADD(a,b,w):如果a,b在同一棵子树中，则将a,b之间路径上所有的点权增加w
query(a,b):如果a,b在同一棵子树中，返回a,b之间路径上点权的最大值
*/
const int maxn = 300010;
int ch[maxn][2],pre[maxn],key[maxn];
int add[maxn],rev[maxn],Max[maxn];
bool rt[maxn];

void Update_Add(int r,int d)
{
	if(!r)
		return;
	key[r] += d;
	add[r] += d;
	Max[r] += d;
}
void Update_Rev(int r)
{
	if(!r)
		return;
	swap(ch[r][0],ch[r][1]);
	rev[r] ^= 1;
}
void push_down(int r)
{
	if(add[r])
	{
		Update_Add(ch[r][0],add[r]);
		Update_Add(ch[r][1],add[r]);
		add[r] = 0;
	}
	if(rev[r])
	{
		Update_Rev(ch[r][0]);
		Update_Rev(ch[r][1]);
		rev[r] = 0;
	}
}
void push_up(int r)
{
	Max[r] = max(max(Max[ch[r][0]],Max[ch[r][1]]),key[r]);
}
void Rotate(int x)
{
	int y = pre[x],kind = ch[y][1] == x;
	ch[y][kind] = ch[x][!kind];
	pre[ch[y][kind]] = y;
	pre[x] = pre[y];
	pre[y] = x;
	ch[x][!kind] = y;
	if(rt[y]){
		rt[y] = false; rt[x] = true;
	}
	else
		ch[pre[x]][ch[pre[x]][1]==y] = x;
	push_up(y);
}
//P函数先将根节点到r的路径上所有的结点的标记逐级下放
void P(int r)
{
	if(!rt[r])
		P(pre[r]);
	push_down(r);
}
void Splay(int r)
{
	P(r);
	while(!rt[r])
	{
		int f = pre[r],ff = pre[f];
		if(rt[f])
			Rotate(r);
		else if((ch[ff][1]==f)==(ch[f][1]==r))
		{
			Rotate(f);Rotate(r);
		}
		else
		{
			Rotate(r);Rotate(r);
		}
	}
	push_up(r);
}
int Access(int x)
{
	int y = 0;
	for(;x;x = pre[y=x])
	{
		Splay(x);
		rt[ch[x][1]] = true;
		rt[ch[x][1]=y] = false;
		push_up(x);
	}
	return y;
}
//判断是否是同根（真实的树，非splay
bool judge(int u,int v)
{
	while(pre[u]) u = pre[u];
	while(pre[v]) v = pre[v];
	return u == v;
}
//使r成为它所在的树的根
void mroot(int r)
{
	Access(r);
	Splay(r);
	Update_Rev(r);
}
//调用后u是原来u和v的LCA，v和ch[u][1]分别存着LCA的2个儿子
//原来u和v所在的2棵子树
void lca(int &u,int &v)
{
	Access(v),v = 0;
	while(u)
	{
		Splay(u);
		if(!pre[u])	return;
		rt[ch[u][1]] = true;
		rt[ch[u][1]=v] = false;
		push_up(u);
		u = pre[v=u];
	}
}
void link(int u,int v)
{
	if(judge(u,v))
	{
		puts("-1");
		return;
	}
	mroot(u);
	pre[u] = v;
}
//使u成为u所在树的根，并且v和它父亲的边断开
void cut(int u,int v)
{
	if(u == v || !judge(u,v))
	{
		puts("-1");
		return;
	}
	mroot(u);
	Splay(v);
	pre[ch[v][0]] = pre[v];
	pre[v] = 0;
	rt[ch[v][0]] = true;
	ch[v][0] = 0;
	push_up(v);
}
void ADD(int u,int v,int w)
{
	if(!judge(u,v))
	{
		puts("-1");
		return;
	}
	lca(u,v);
	Update_Add(ch[u][1],w);
	Update_Add(v,w);
	key[u] += w;
	push_up(u);
}
void query(int u,int v)
{
	if(!judge(u, v))
	{
		puts("-1");
		return;
	}
	lca(u,v);
	printf("%d\n",max(max(Max[v],Max[ch[u][1]]),key[u]));
}
struct Edge
{
	int to,next;	
}edge[maxn*2];
int head[maxn],tot;
void addedge(int u,int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs(int u)
{
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v = edge[i].to;
		if(pre[v]!=0)
			continue;
		pre[v] = u;
		dfs(v);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,q,u,v;
	while(cin>>n)
	{
		tot = 0;
		for(int i=0;i<=n;i++)
		{
			head[i] = -1;
			pre[i] = 0;
			ch[i][0] = ch[i][1] = 0;
			rev[i] = 0;
			add[i] = 0;
			rt[i] = true;
		}
		Max[0] = -2000000000;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			addedge(u,v);
			addedge(v,u);
		}
		for(int i=1;i<=n;i++)
		{
			cin>>key[i];
			Max[i] = key[i];
		}
		cin>>q;
		pre[1] = -1;
		dfs(1);
		pre[1] = 0;
		int op;
		while(q--)
		{
			cin>>op;
			if(op == 1)
			{
				int x,y;
				cin>>x>>y;
				link(x,y);
			}
			else if(op == 2)
			{
				int x,y;
				cin>>x>>y;
				cut(x,y);
			}
			else if(op == 3)
			{
				int w,x,y;
				cin>>w>>x>>y;
				ADD(x,y,w);
			}
			else
			{
				int x,y;
				cin>>x>>y;
				query(x,y);
			}
		}
		cout<<"\n";
	}
	return 0;
}
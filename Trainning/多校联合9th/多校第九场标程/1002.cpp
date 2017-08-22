#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAXN 100000
#define MAXM 100000

struct edge
{
	int x,y,next;
};

struct node
{
	int id,x,d;
	node(int idid = 0,int xx = 0,int dd = 0)
	{
		id = idid;
		x = xx;
		d = dd;
	}
};

struct treap
{
	long long data;
	long long sum;
	int siz;
	int key;
	treap* son[2];
};

treap* root = NULL;
int n,m;
long long c[MAXN+5];
edge v[MAXN*2+5];
int head[MAXN+5];
int deep[MAXN+5];
int f[MAXN+5][20];
int tot;
long long ans[MAXM+5];
vector<node> q[MAXN+5];

void add(int x,int y)
{
	tot++;
	v[tot].x = x; v[tot].y = y;
	v[tot].next = head[x]; head[x] = tot;
}

void dfs(int x,int fa)
{
	for (int i=head[x];i;i=v[i].next)
	{
		if (v[i].y == fa) continue;
		deep[v[i].y] = deep[x]+1;
		f[v[i].y][0] = x;
		dfs(v[i].y,x);
	}
}

void prepare()
{
	for (int j=0;j<17;j++)
	{
		for (int i=1;i<=n;i++)
		{
			f[i][j+1] = f[f[i][j]][j];
		}
	}
}

int LCA(int x,int y)
{
	if (deep[x] < deep[y]) swap(x,y);
	for (int i=18;i>=0;i--)
	{
		if (deep[y] <= deep[f[x][i]])
		{
			x = f[x][i];
		}
	}
	if (x == y) return x;
	for (int i=18;i>=0;i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

void update(treap* &t)
{
	if (t == NULL) return;
	t->siz = 1;
	t->sum = t->data;
	if (t->son[0] != NULL) 
	{
		t->siz += t->son[0]->siz;
		t->sum += t->son[0]->sum;
	}
	if (t->son[1] != NULL)
	{
		t->siz += t->son[1]->siz;
		t->sum += t->son[1]->sum;
	}
}

void Rot(treap* &t,int d)
{
	treap* k = t->son[d^1];
	t->son[d^1] = k->son[d];
	k->son[d] = t;
	update(t);
	update(k);
	t = k;
}

void Ins(treap* &t,long long x)
{
	if (t == NULL)
	{
		t = new treap;
		t->data = t->sum = x;
		t->son[0] = t->son[1] = NULL;
		t->siz = 1;
		return;
	}
	int d = x<t->data?0:1;
	Ins(t->son[d],x);
	if (t->son[d]->key>t->key)
	{
		Rot(t,d^1);
	}
	update(t);
}

void Del(treap* &t,long long x)
{
	if (t->data == x)
	{
		treap* temp = t;
		if (t->son[0] == NULL)
		{
			t = t->son[1];
			delete temp;
			temp = NULL;
		}
		else if (t->son[1] == NULL)
		{
			t = t->son[0];
			delete temp;
			temp = NULL;
		}
		else
		{
			int k = t->son[0]->key>t->son[1]->key?1:0;
			Rot(t,k);
			Del(t->son[k],x);
		}
	}
	else if (x < t->data)
	{
		Del(t->son[0],x);
	}
	else
	{
		Del(t->son[1],x);
	}
	if (t != NULL) update(t);
}

long long Ask(treap* t,long long x)
{
	if (t == NULL) return 0;
	long long temp = 0;
	if (t->data > x)
	{
		temp = Ask(t->son[0],x);
	}
	else
	{
		temp = t->data+Ask(t->son[1],x);
		if (t->son[0] != NULL)
		{
			temp += t->son[0]->sum;
		}
	}
	return temp;
}

void Print(treap* &x)
{
	if (x == NULL) return;
	Print(x->son[0]);
	printf("%I64d ",x->data);
	Print(x->son[1]);
}

void dfs2(int x,int fa)
{
	Ins(root,c[x]);
	node now;
	int N = q[x].size();
	for (int i=0;i<N;i++)
	{
		now = q[x][i];
		ans[now.id] += now.d*Ask(root,now.x);
	}
	for (int i=head[x];i;i=v[i].next)
	{
		if (v[i].y == fa) continue;
		dfs2(v[i].y,x);
	}
	Del(root,c[x]);
}

int main()
{
	//freopen("input.txt","r",stdin);
	srand((unsigned int)time(0));
	int x,y,z,a,b;
	scanf("%d%d",&n,&m);
	
	tot = 0;
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(f,0,sizeof(f));
	deep[1] = 1;
	root = NULL;
	memset(ans,0,sizeof(ans));
	q[0].clear();
	
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&c[i]);
		q[i].clear();
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	
	dfs(1,0);
	prepare();
	node temp;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		z = LCA(x,y);
		q[x].push_back(node(i,b,1));
		q[y].push_back(node(i,b,1));
		q[z].push_back(node(i,b,-1));
		q[f[z][0]].push_back(node(i,b,-1));
		q[x].push_back(node(i,a-1,-1));
		q[y].push_back(node(i,a-1,-1));
		q[z].push_back(node(i,a-1,1));
		q[f[z][0]].push_back(node(i,a-1,1));
	}

	dfs2(1,0);
	
	for (int i=1;i<=m;i++)
	{
		printf("%I64d%c",ans[i],i==m?'\n':' ');
	}
	
	return 0;
}

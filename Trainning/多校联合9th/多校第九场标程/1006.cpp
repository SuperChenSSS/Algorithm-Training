#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 100010
#define INF 0x3f3f3f3f3f3f3f3fLL
#define LL long long
#define p E[i].x
#define bit(x) (1<<(x))

using namespace std;

struct node
{
	int x;
	LL v;
	bool operator<(const node &tmp)const
	{
		return v>tmp.v;
	}
};

priority_queue<node> q;

struct edge
{
	int x,to,v;
}E[N<<1];

int n,m,totE,g[N],X[N],Y[N],Z[N],a[N];
LL dist[N];
bool v[N];

void addedge(int x,int y,int v)
{
	E[++totE] = (edge){y,g[x],v}; g[x] = totE;
}

LL calc_dist(int S,int T)
{
	for(int i=0;i<=n+1;i++) dist[i] = INF, v[i] = 0;
	dist[S]=0;
	q.push((node){S,0});
	node tmp;
	while(!q.empty())
	{
		tmp = q.top(); q.pop();
		int x = tmp.x;
		if(v[x]) continue;
		v[x] = 1;
		for(int i=g[x];i;i=E[i].to)
			if(!v[p] && dist[p]>dist[x]+E[i].v)
			{
				dist[p] = dist[x] + E[i].v;
				q.push((node){p,dist[p]});
			}
	}
	return dist[T];
}

int main()
{
    //freopen("in0.txt","r",stdin);
	int T,K,Te = 0;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		scanf("%d",&K);
		for(int i=1;i<=K;i++) scanf("%d",&a[i]);
		LL ans = INF;
		for(int t=0;t<20;t++)
		{
			totE = 0;
			for(int i=0;i<=n+1;i++) g[i] = 0;
			for(int i=1;i<=m;i++) addedge(X[i],Y[i],Z[i]);
			for(int i=1;i<=K;i++)
			{
				if(a[i]&bit(t)) addedge(0,a[i],0);
				else addedge(a[i],n+1,0);
			}
			ans = min(ans, calc_dist(0,n+1));
			totE = 0;
			for(int i=0;i<=n+1;i++) g[i] = 0;
			for(int i=1;i<=m;i++) addedge(X[i],Y[i],Z[i]);
			for(int i=1;i<=K;i++)
			{
				if((a[i]&bit(t))==0) addedge(0,a[i],0);
				else addedge(a[i],n+1,0);
			}
			ans = min(ans, calc_dist(0,n+1));
		}
		//assert( ans < INF );
		printf("Case #%d: %lld\n",++Te,ans);
	}
	return 0;
}

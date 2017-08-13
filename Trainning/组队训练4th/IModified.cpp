#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <cmath>
#define INF 0xfffffff
using namespace std;

const int maxn=1010;
const int maxm=maxn*maxn*2;


int dfn[maxn],low[maxn],head[maxn];
int num,tot;
int ans;

struct node{
	int v,c,next,id;
}e[maxm];

int n,m;

void tarjan(int u,int fa){
	dfn[u]=low[u]=++num;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		int id=e[i].id;
		if(fa==id) continue;
		if(!dfn[v]){
			tarjan(v,id);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v]){
				ans=min(ans,e[i].c);
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}

void add(int u,int v,int c,int id){
	e[tot].c=c;
	e[tot].v=v;
	e[tot].id=id;
	e[tot].next=head[u];
	head[u]=tot++;
}

int main()
{
	while(cin>>n>>m && n||m){
		int u,v,c;
		tot=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=m;++i){
			cin>>u>>v>>c;
			add(u,v,c,i);
			add(v,u,c,i);
		}
		memset(dfn,0,sizeof(dfn));
		num=0;
		int ok=0;
		ans=INF;
		for(int i=1;i<=n;++i)
			if(!dfn[i]){
				ok++;
				tarjan(i,0);
			}
		if(ans==0) ans=1;
		if(ans==INF) ans=-1;
		if(ok>1) ans=0;
	   // for(int i=1;i<=n;++i) cout<<dfn[i]<<"    "<<low[i]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
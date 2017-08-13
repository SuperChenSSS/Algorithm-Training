#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100010;
int Case,n,m,i,x,y,w,g[N],v[N<<1],nxt[N<<1],ed,size[N],d[N],f[N],son[N],top[N];
int same[N],fa[N],cnt[N];long long cost[N];
struct E{int a,b,c,d,w;}e[N];
inline bool cmp(const E&a,const E&b){return a.w<b.w;}
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void dfs(int x){
  size[x]=1;
  for(int i=g[x];i;i=nxt[i])if(v[i]!=f[x]){
    f[v[i]]=x,d[v[i]]=d[x]+1;
    dfs(v[i]),size[x]+=size[v[i]];
    if(size[v[i]]>size[son[x]])son[x]=v[i];
  }
}
void dfs2(int x,int y){
  top[x]=y;
  if(son[x])dfs2(son[x],y);
  for(int i=g[x];i;i=nxt[i])if(v[i]!=f[x]&&v[i]!=son[x])dfs2(v[i],v[i]);
}
inline int lca(int x,int y){
  for(;top[x]!=top[y];x=f[top[x]])if(d[top[x]]<d[top[y]])swap(x,y);
  return d[x]<d[y]?x:y;
}
int Same(int x){return same[x]==x?x:same[x]=Same(same[x]);}
int Fa(int x){return fa[x]==x?x:fa[x]=Fa(fa[x]);}
inline void merge(int x,int y){
  x=Fa(x),y=Fa(y);
  if(x==y)return;
  fa[x]=y;
  cnt[y]+=cnt[x];
  cost[y]+=cost[x]+w;
}
inline void go(int x,int y){
  while(1){
    x=Same(x);
    if(d[x]<=d[y])return;
    merge(x,f[x]);
    same[x]=f[x];
  }
}
inline void chain(int x,int y){
  int z=lca(x,y);
  go(x,z),go(y,z);
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1);dfs2(1,1);
    for(i=1;i<=n;i++)same[i]=fa[i]=i,cnt[i]=1,cost[i]=0;
    for(i=1;i<=m;i++)scanf("%d%d%d%d%d",&e[i].a,&e[i].b,&e[i].c,&e[i].d,&e[i].w);
    sort(e+1,e+m+1,cmp);
    for(i=1;i<=m;i++){
      w=e[i].w;
      chain(e[i].a,e[i].b);
      chain(e[i].c,e[i].d);
      merge(e[i].a,e[i].c);
    }
    printf("%d %lld\n",cnt[Fa(1)],cost[Fa(1)]);
    for(ed=0,i=1;i<=n;i++)g[i]=size[i]=d[i]=f[i]=son[i]=top[i]=0;
  }
  return 0;
}
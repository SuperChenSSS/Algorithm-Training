#include<cstdio>
typedef unsigned int U;
const int N=255;
int Case,n,m,k,i,j,x,y,now,ans,t,q[N];char s[N];
struct BIT{
  U v[8];
  void clear(){for(int i=0;i<8;i++)v[i]=0;}
  void set(int x){v[x>>5]|=1U<<(x&31);}
  void flip(int x){v[x>>5]^=1U<<(x&31);}
  int get(int x){return v[x>>5]>>(x&31)&1;}
}vis,g0[N],g1[N];
inline void flipedge(int x,int y){
  g0[x].flip(y);
  g1[y].flip(x);
}
void dfs0(int x){
  vis.flip(x);
  for(int i=0;i<8;i++)while(1){
    U o=vis.v[i]&g0[x].v[i];
    if(!o)break;
    dfs0(i<<5|__builtin_ctz(o));
  }
  q[++t]=x;
}
void dfs1(int x){
  vis.flip(x);now++;
  for(int i=0;i<8;i++)while(1){
    U o=vis.v[i]&g1[x].v[i];
    if(!o)break;
    dfs1(i<<5|__builtin_ctz(o));
  }
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)g0[i].clear(),g1[i].clear();
    for(i=0;i<n;i++){
      scanf("%s",s);
      for(j=0;j<n;j++)if(s[j]=='1')flipedge(i,j);
    }
    while(m--){
      scanf("%d",&k);
      while(k--)scanf("%d%d",&x,&y),flipedge(x-1,y-1);
      vis.clear();
      for(ans=i=0;i<n;i++)vis.set(i);
      for(t=i=0;i<n;i++)if(vis.get(i))dfs0(i);
      for(i=0;i<n;i++)vis.set(i);
      for(i=n;i;i--)if(vis.get(q[i])){
        now=0;
        dfs1(q[i]);
        ans+=now*(now-1)/2;
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}
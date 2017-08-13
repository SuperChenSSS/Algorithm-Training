#include<cstdio>
const int N=300010*2,P=998244353;
int Case,n,i,j,x,y,ans,h,t,q[N],g[N],v[N<<1],w[N<<1],nxt[N<<1],ed,d[N];bool vis[N];
inline void add(int x,int y,int z){
  d[x]++,d[y]++;
  v[++ed]=y;w[ed]=z;nxt[ed]=g[x];g[x]=ed;
  v[++ed]=x;w[ed]=z;nxt[ed]=g[y];g[y]=ed;
}
inline int go(int x){
  for(int i=g[x];i;i=nxt[i])if(!vis[v[i]])return v[i];
  return 0;
}
inline int get(int x,int y){for(int i=g[x];i;i=nxt[i])if(v[i]==y)return w[i];}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)for(j=0;j<2;j++)scanf("%d%d",&x,&y),add(i,x+n,y);
    n<<=1;
    for(ans=h=i=1,t=0;i<=n;i++)if(d[i]==1)q[++t]=i;
    while(h<=t){
      for(i=g[x=q[h++]];i;i=nxt[i])if(!vis[v[i]]){
        y=v[i];
        ans=1LL*ans*w[i]%P;
        break;
      }
      vis[x]=vis[y]=1;
      for(i=g[y];i;i=nxt[i])if(!vis[x=v[i]]){
        d[x]--;
        if(d[x]==1)q[++t]=x;
      }
    }
    for(i=1;i<=n;i++)if(!vis[i]){
      vis[q[t=1]=i]=1;
      for(j=go(i);j;j=go(j))vis[q[++t]=j]=1;
      q[t+1]=q[1];
      x=y=1;
      for(j=1;j<=t;j+=2)x=1LL*x*get(q[j],q[j+1])%P;
      for(j=2;j<=t;j+=2)y=1LL*y*get(q[j],q[j+1])%P;
      ans=1LL*ans*(x+y)%P;
    }
    printf("%d\n",ans);
    for(ed=0,i=1;i<=n;i++)g[i]=d[i]=vis[i]=0;
  }
  return 0;
}
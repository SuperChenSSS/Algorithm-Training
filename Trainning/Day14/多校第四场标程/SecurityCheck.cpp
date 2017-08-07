#include<cstdio>
const int N=60010,M=12*2;
int Case,n,m,K,i,j,a[N],b[N],c[N],f[N][M],g[N<<1],v[N*M],nxt[N*M],ed,q[N*M],st[N<<1],en[N<<1];
inline int abs(int x){return x>0?x:-x;}
inline int min(int a,int b){return a<b?a:b;}
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
inline int ask(int l,int r,int x){
  int t=0,mid;
  while(l<=r)if(q[mid=(l+r)>>1]<=x)l=(t=mid)+1;else r=mid-1;
  return q[t];
}
int dp(int x,int y){
  if(!x||!y)return x+y;
  if(abs(a[x]-b[y])<=K){
    int&g=f[x][a[x]-b[y]+K];
    if(g)return g;
    return g=min(dp(x-1,y),dp(x,y-1))+1;
  }
  int t=ask(st[x-y+n],en[x-y+n],x);
  return t?dp(t,y-x+t)+x-t:(x>y?x:y);
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]),c[b[i]]=i;
    for(i=n;i;i--)for(j=a[i]-K;j<=a[i]+K;j++)if(1<=j&&j<=n)add(i-c[j]+n,i);
    for(i=1;i<n+n;en[i++]=m)for(st[i]=m+1,j=g[i];j;j=nxt[j])q[++m]=v[j];
    printf("%d\n",dp(n,n));
    m=ed=0;
    for(i=1;i<=n;i++)for(j=0;j<=K*2;j++)f[i][j]=0;
    for(i=1;i<n+n;i++)g[i]=0;
  }
  return 0;
}
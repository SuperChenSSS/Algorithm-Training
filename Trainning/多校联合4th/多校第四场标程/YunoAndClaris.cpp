#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010,M=200,K=9;
int Case,n,m,lim,i,j,op,l,r,x,y,a[N];
int en[M],f[M][N],g[M][N];bool flag[M];
int c[N][M],b[M][M],c1[N],b1[M],q[2000];
inline void remake(int x){
  if(!flag[x])return;
  flag[x]=0;
  int i,r=en[x];
  for(i=x<<K;i<=r;i++)f[x][a[i]]=0,a[i]=g[x][a[i]];
  for(i=x<<K;i<=r;i++)f[x][a[i]]=g[x][a[i]]=a[i];
}
inline void change(int l,int r,int x,int y){
  if(x==y)return;
  int L=l>>K,R=r>>K,X=x>>K,Y=y>>K,i,j,t,tL=0,tR=0;
  if(L==R){
    if(!f[L][x])return;
    remake(L);
    for(t=0,i=l;i<=r;i++)if(a[i]==x)a[i]=y,t++;
    if(t){
      f[L][y]=g[L][y]=y;
      if(X==Y)for(i=L;i<=lim;i++)c[x][i]-=t,c[y][i]+=t;
      else for(i=L;i<=lim;i++)c[x][i]-=t,c[y][i]+=t,b[X][i]-=t,b[Y][i]+=t;
    }
    t=c[x][L];
    if(L)t-=c[x][L-1];
    if(!t)f[L][x]=0;
    return;
  }
  if(f[R][x]){
    remake(R);
    for(t=0,i=r;(i>>K)==R;i--)if(a[i]==x)a[i]=y,t++;
    tR=t;
    if(t)f[R][y]=g[R][y]=y;
    if(c[x][R]-t==c[x][R-1])f[R][x]=0;
  }
  if(f[L][x]){
    remake(L);
    for(t=0,i=l;(i>>K)==L;i++)if(a[i]==x)a[i]=y,t++;
    tL=t;
    if(t){
      f[L][y]=g[L][y]=y;
      c[x][L]-=t,c[y][L]+=t,b[X][L]-=t,b[Y][L]+=t;
    }
    t=c[x][L];
    if(L)t-=c[x][L-1];
    if(!t)f[L][x]=0;
  }
  for(i=L+1;i<R;i++)if(f[i][x]){
    if(f[i][y]){
      remake(i);
      for(j=i<<K;j<((i+1)<<K);j++)if(a[j]==x)a[j]=y;
      f[i][x]=0;
      continue;
    }
    j=f[i][y]=f[i][x];
    f[i][x]=0;
    g[i][j]=y;
    flag[i]=1;
  }
  if(L+1==R){
    t=tL+tR;
    if(!t)return;
    if(X==Y)for(i=R;i<=lim;i++)c[x][i]-=t,c[y][i]+=t;
    else for(i=R;i<=lim;i++)c[x][i]-=t,c[y][i]+=t,b[X][i]-=t,b[Y][i]+=t;
    return;
  }
  int o=c[x][L];
  if(X==Y){
    for(i=L+1;i<R;i++){
      t=c[x][i]-o;
      c[x][i]-=t,c[y][i]+=t;
    }
    t+=tR;
    if(!t)return;
    for(;i<=lim;i++)c[x][i]-=t,c[y][i]+=t;
  }else{
    for(i=L+1;i<R;i++){
      t=c[x][i]-o;
      c[x][i]-=t,c[y][i]+=t,b[X][i]-=t,b[Y][i]+=t;
    }
    t+=tR;
    if(!t)return;
    for(;i<=lim;i++)c[x][i]-=t,c[y][i]+=t,b[X][i]-=t,b[Y][i]+=t;
  }
}
inline int ask(int l,int r,int k){
  int L=l>>K,R=r>>K,i,t;
  remake(L);
  if(L<R)remake(R);
  if(L+1>=R){
    for(t=0,i=l;i<=r;i++)q[t++]=a[i];
    nth_element(q,q+k-1,q+t);
    return q[k-1];
  }
  for(i=0;i<=lim;i++)b1[i]=0;
  for(i=l;(i>>K)==L;i++)c1[a[i]]++,b1[a[i]>>K]++;
  for(i=r;(i>>K)==R;i--)c1[a[i]]++,b1[a[i]>>K]++;
  for(i=0;;i++){
    t=b[i][R-1]-b[i][L]+b1[i];
    if(k>t)k-=t;else break;
  }
  for(i<<=K;;i++){
    t=c[i][R-1]-c[i][L]+c1[i];
    if(k>t)k-=t;else break;
  }
  t=i;
  for(i=l;(i>>K)==L;i++)c1[a[i]]--;
  for(i=r;(i>>K)==R;i--)c1[a[i]]--;
  return t;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    lim=n>>K;
    for(i=1;i<=n;i++)en[i>>K]=i;
    for(i=0;i<=lim;i++){
      flag[i]=0;
      for(j=1;j<=n;j++)f[i][j]=0;
    }
    for(i=1;i<=n;i++)for(j=0;j<=lim;j++)c[i][j]=0;
    for(i=0;i<=lim;i++)for(j=0;j<=lim;j++)b[i][j]=0;
    for(i=1;i<=n;i++){
      j=i>>K;
      f[j][a[i]]=g[j][a[i]]=a[i];
      c[a[i]][j]++;
      b[a[i]>>K][j]++;
    }
    for(i=1;i<=n;i++)for(j=1;j<=lim;j++)c[i][j]+=c[i][j-1];
    for(i=0;i<=lim;i++)for(j=1;j<=lim;j++)b[i][j]+=b[i][j-1];
    while(m--){
      scanf("%d%d%d%d",&op,&l,&r,&x);
      if(op==1)scanf("%d",&y),change(l,r,x,y);
      if(op==2)printf("%d\n",ask(l,r,x));
    }
  }
  return 0;
}
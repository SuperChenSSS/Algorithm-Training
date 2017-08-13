#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=131072,K=16,P=786433,G=10;
int Case,S,n,m,i,j,k,x,y,mx,base,tmp,fin;bool can[9][N+5];
int a[9][N+5],f[N+5],c[N+5],ans[N+5],pos[N+5];
int g[K+1],ng[K+5],inv[P],pre[P],fac[P],inv2;
char s[N+5];
inline int pow(int a,int b){int t=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)t=1LL*t*a%P;return t;}
inline void NTT(int*a,int n,int t){
  for(int i=1;i<n;i++)if(i<pos[i])swap(a[i],a[pos[i]]);
  for(int d=0;(1<<d)<n;d++){
    int m=1<<d,m2=m<<1,_w=t==1?g[d]:ng[d];
    mx=_w;
    for(int i=0;i<n;i+=m2)for(int w=1,j=0;j<m;j++){
      int&A=a[i+j+m],&B=a[i+j],t=1LL*w*A%P;
      A=B-t>=0?B-t:B-t+P;
      B=B+t<P?B+t:B+t-P;
      w=1LL*w*_w%P;
    }
  }
  if(t==-1)for(int i=0,j=inv[n];i<n;i++)a[i]=1LL*a[i]*j%P;
}
inline void up(int&x,int y){x=x+y<P?x+y:x+y-P;}
inline void add(int x,int y){if(y)f[x]=1LL*f[x]*y%P;else c[x]++;}
inline void del(int x,int y){if(y)f[x]=1LL*f[x]*inv[y]%P;else c[x]--;}
int main(){
  for(g[K]=pow(G,(P-1)/N),ng[K]=pow(g[K],P-2),i=K-1;~i;i--)g[i]=1LL*g[i+1]*g[i+1]%P,ng[i]=1LL*ng[i+1]*ng[i+1]%P;
  for(inv[1]=1,i=2;i<P;i++)inv[i]=1LL*(P-inv[P%i])*(P/i)%P;inv2=inv[2];
  for(pre[0]=pre[1]=1,i=2;i<P;i++)pre[i]=1LL*pre[i-1]*inv[i]%P;
  for(fac[0]=fac[1]=1,i=2;i<P;i++)fac[i]=1LL*fac[i-1]*i%P;
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d%d",&S,&n,&m);S--;
    for(k=1;k<=n*S;k<<=1);
    j=__builtin_ctz(k)-1;
    for(i=0;i<k;i++)pos[i]=0;
    for(i=0;i<k;i++)pos[i]=pos[i>>1]>>1|((i&1)<<j);
    for(i=0;i<k;i++)f[i]=1,c[i]=0;
    for(i=0;i<S;i++){
      for(j=0;j<k;j++)a[i][j]=0;
      scanf("%s",s);
      for(j=0;j<=n;j++)if(s[j]=='1')a[i][j]=pre[j],can[i][j]=1;else can[i][j]=0;
      NTT(a[i],k,1);
      for(j=0;j<k;j++)add(j,a[i][j]);
    }
    for(i=0;i<k;i++)ans[i]=c[i]?0:f[i];
    while(m--){
      scanf("%d%d",&x,&y);x--;
      base=pow(mx,y);
      tmp=pre[y];
      if(can[x][y])tmp=(P-tmp)%P;
      for(i=0;i<k;i++,tmp=1LL*tmp*base%P){
        del(i,a[x][i]);
        up(a[x][i],tmp);
        add(i,a[x][i]);
        if(!c[i])up(ans[i],f[i]);
      }
      can[x][y]^=1;
    }
    NTT(ans,k,-1);
    for(fin=0,i=1;i<k;i++)if(ans[i])fin=(1LL*ans[i]*fac[i]+fin)%P;
    printf("%d\n",fin);
  }
  return 0;
}
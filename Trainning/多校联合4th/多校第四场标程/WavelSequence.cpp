#include<cstdio>
const int N=2010,P=998244353;
int Case,n,m,i,j,k,t,a[N],b[N],g[N][N][2],h[N][N][2],ans;
inline void up(int&x,int y){x=x+y<P?x+y:x+y-P;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)scanf("%d",&b[i]);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<2;k++)g[i][j][k]=h[i][j][k]=0;
    for(ans=0,i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<2;k++){
      if(a[i]==b[j]){
        t=h[i][j][k^1];
        if(!k)up(t,1);
        if(t){
          up(ans,t);
          up(g[i+1][j][k],t);
        }
      }
      if(g[i][j][k]){
        up(g[i+1][j][k],g[i][j][k]);
        if(!k){if(a[i]>b[j])up(h[i][j+1][k],g[i][j][k]);}
        else if(a[i]<b[j])up(h[i][j+1][k],g[i][j][k]);
      }
      if(h[i][j][k])up(h[i][j+1][k],h[i][j][k]);
    }
    printf("%d\n",ans);
  }
  return 0;
}
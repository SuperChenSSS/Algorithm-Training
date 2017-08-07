#include<cstdio>
const int N=50005,M=105;
int Case,n,m,q,i,j,k,x,y,nxt[M],g[M][26],c[M][26],pre[N],s[N][M],suf[N][M];
char a[N],b[M];long long ans;
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d%d%s%s",&n,&m,&q,a+1,b+1);
    for(i=1;i<=n;i++)a[i]-='a';
    for(i=1;i<=m;i++)b[i]-='a';
    for(nxt[1]=j=0,i=2;i<=m;nxt[i++]=j){
      while(j&&b[j+1]!=b[i])j=nxt[j];
      if(b[j+1]==b[i])j++;
    }
    for(i=0;i<m;i++)for(j=0;j<26;j++){
      c[i][j]=0;
      for(k=i;k&&b[k+1]!=j;k=nxt[k]);
      if(b[k+1]==j)k++;
      if(k==m)k=nxt[k],c[i][j]=1;
      g[i][j]=k;
    }
    for(i=1,j=k=0;i<=n;i++){
      k+=c[j][a[i]];
      j=g[j][a[i]];
      pre[i]=pre[i-1]+k;
      for(x=0;x<m;x++)s[i][x]=s[i-1][x];
      s[i][j]++;
    }
    for(j=0;j<m;j++)suf[n+1][j]=0;
    for(i=n;i;i--)for(j=0;j<m;j++)suf[i][j]=c[j][a[i]]+suf[i+1][g[j][a[i]]];
    for(i=n;i;i--)for(j=0;j<m;j++)suf[i][j]+=suf[i+1][j];
    while(q--){
      scanf("%d%d",&x,&y);
      ans=1LL*(n-y+1)*pre[x];
      for(i=0;i<m;i++)ans+=1LL*s[x][i]*suf[y][i];
      printf("%lld\n",ans);
    }
  }
  return 0;
}
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;
const ll inf=2000000000000000000LL;
int Case,g[4],i,j,m;ll f[4][60000],K,ans;priority_queue<P,vector<P>,greater<P> >q;
inline void ext(int x,int y,ll z){if(f[x][y]>z)q.push(P(f[x][y]=z,y<<2|x));}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%lld%d%d%d%d",&K,&g[0],&g[1],&g[2],&g[3]);
    m=min(g[0],g[1])*2;
    for(i=0;i<4;i++)for(j=0;j<m;j++)f[i][j]=inf;
    ext(1,0,0);
    while(!q.empty()){
      P t=q.top();q.pop();
      int x=t.second&3,y=t.second>>2;
      if(f[x][y]<t.first)continue;
      ext((x+1)&3,(y+g[x])%m,t.first+g[x]);
      ext((x+3)&3,(y+g[(x+3)&3])%m,t.first+g[(x+3)&3]);
    }
    ans=inf;
    for(i=0;i<m;i++)if(f[1][i]<K){
      ll t=(K-f[1][i])/m*m+f[1][i];
      while(t<K)t+=m;
      ans=min(ans,t);
    }else ans=min(ans,f[1][i]);
    printf("%lld\n",ans);
  }
  return 0;
}
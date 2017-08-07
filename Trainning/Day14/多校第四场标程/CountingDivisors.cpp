#include <cstdio>
typedef long long ll;
const int N=1000010,P=998244353;
int Case,i,j,k,p[N/10],tot,g[N],ans;ll n,l,r,f[N];bool v[N];
inline void work(ll p){
  for(ll i=l/p*p;i<=r;i+=p)if(i>=l){
    int o=0;
    while(f[i-l]%p==0)f[i-l]/=p,o++;
    g[i-l]=1LL*g[i-l]*(o*k+1)%P;
  }
}
int main(){
  for(i=2;i<N;i++){
    if(!v[i])p[tot++]=i;
    for(j=0;j<tot&&i*p[j]<N;j++){
      v[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
  scanf("%d",&Case);
  while(Case--){
    scanf("%lld%lld%d",&l,&r,&k);
    n=r-l;
    for(i=0;i<=n;i++)f[i]=i+l,g[i]=1;
    for(i=0;i<tot;i++){
      if(1LL*p[i]*p[i]>r)break;
      work(p[i]);
    }
    for(ans=i=0;i<=n;i++){
      if(f[i]>1)g[i]=1LL*g[i]*(k+1)%P;
      ans=(ans+g[i])%P;
    }
    printf("%d\n",ans);
  }
  return 0;
}
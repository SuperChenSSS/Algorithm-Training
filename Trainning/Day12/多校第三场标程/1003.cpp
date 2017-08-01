#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=510000;
inline void read(int &x){
    x=0;char p=getchar();
    while(!(p<='9'&&p>='0'))p=getchar();
    while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
int n,k,a[N],pos[N],T;
LL ans=0;
int pre[N],np[N];
int s[N],s0;
int t[N],t0;
void erase(int x){
    int pp=pre[x];
    int nn=np[x];
    if(pre[x])np[pre[x]]=nn;
    if(np[x]<=n)pre[np[x]]=pp;
    pre[x]=np[x]=0;
}
void Main(){
    read(n);read(k);
    rep(i,1,n){
        read(a[i]);
        pos[a[i]]=i;
    }
    rep(i,1,n)pre[i]=np[i]=0;
    rep(i,1,n)pre[i]=i-1,np[i]=i+1;
    ans=0;
    rep(num,1,n-k+1){
        int p=pos[num];
        s0=t0=0;
        for(int d=p;d&&s0<=k+1;d=pre[d])s[++s0]=d;
        for(int d=p;d!=n+1&&t0<=k+1;d=np[d])t[++t0]=d;
        s[++s0]=0;
        t[++t0]=n+1;
        rep(i,1,s0-1){
            if(k+1-i<=t0-1&&k+1-i>=1){
                ans+=(t[k+1-i+1]-t[k+1-i])*1ll*(s[i]-s[i+1])*num;
            }
        }
        erase(p);
    }
    cout<<ans<<endl;
}
int main(){
    read(T);
    while(T--)Main();
    //cerr<<clock()<<endl;
    return 0;
}

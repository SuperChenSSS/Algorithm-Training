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
int a[N];
int go[N*32][2],tot;
LL ss[N*32];
int num[N*32];
int sum[N][32][2];
int n,T;
int main(){
    read(T);
    while(T--){
        rep(i,1,tot)rep(j,0,1)go[i][j]=0;
        rep(i,1,tot)ss[i]=num[i]=0;
        rep(i,1,n)rep(j,0,29)rep(k,0,1)sum[i][j][k]=0;
        tot=1;
        read(n);
        rep(i,1,n)read(a[i]);
        rep(i,1,n){
            rep(j,0,29)rep(k,0,1)sum[i][j][k]=sum[i-1][j][k];
            rep(j,0,29){
                int v=((a[i]&(1<<j))>0);
                sum[i][j][v]++;
            }
        }
        LL ans=0;
        per(i,n,1){
            int now=1;
            per(j,29,0){
                int v=((a[i]&(1<<j))>0);
                if(go[now][v^1]){
                    ans+=ss[go[now][v^1]]-num[go[now][v^1]]*1ll*sum[i][j][v];
                }
                if(!go[now][v])break;
                now=go[now][v];
            }
            now=1;
            per(j,29,0){
                int v=((a[i]&(1<<j))>0);
                if(!go[now][v])go[now][v]=++tot;
                now=go[now][v];
                ss[now]+=sum[i-1][j][v^1];
                num[now]++;
            }
        }
        cout<<ans<<endl;
    }
    //cerr<<clock()<<endl;
    return 0;
}

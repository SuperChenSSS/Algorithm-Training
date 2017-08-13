#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=998244353;
const int N=(1<<20);
inline void read(int &x){
    x=0;char p=getchar();
    while(!(p<='9'&&p>='0'))p=getchar();
    while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
int n,A[N],B[N],C[N],m;
int bit[N];
int aa[N][21];
int bb[N][21];
int cc[N][21];
unsigned long long ds[21];
void FWT(int a[N][21],int ff){
    //int mao=clock();
    for(int i=1;i<n;i<<=1)
    for(int j=0;j<n;j+=(i<<1))
    rep(k,0,i-1){
        rep(l,0,m){
            int v0=a[j+k][l];
            int v1=a[i+j+k][l];
            a[j+k][l]=(v0+v1)%P;
            a[i+j+k][l]=(v0+P-v1)%P;
        }
    }
    if(ff==1){
        int p2=Pow((P+1)>>1,m);
        rep(i,0,n-1)rep(j,0,m)a[i][j]=a[i][j]*1ll*p2%P;
    }
    //cerr<<"Time:"<<clock()-mao<<endl;
}
int main(){
    read(m);n=1<<m;
    rep(i,0,n-1)read(A[i]);
    rep(i,0,n-1)read(B[i]);
    rep(i,0,n-1)bit[i]=bit[i>>1]+(i&1);
    rep(i,0,n-1)A[i]=A[i]*1ll*(1<<bit[i])%P;

    rep(i,0,n-1){
        aa[i][bit[i]]=A[i];
        bb[i][bit[i]]=B[i];
    }
    FWT(aa,0);
    FWT(bb,0);
    rep(i,0,n-1){
        memset(ds,0,sizeof ds);
        rep(j,0,m)rep(k,0,j){
            ds[j-k]=(ds[j-k]+bb[i][j]*1ll*aa[i][k]);
            if(ds[j-k]>=1ll<<63)ds[j-k]%=P;
        }
        rep(j,0,m)cc[i][j]=ds[j]%P;
    }
    FWT(cc,1);
    rep(i,0,n-1){
        C[i]=cc[i][bit[i]];
    }
    int ans=0;
    int base=1;
    rep(i,0,n-1){
        ans=(ans+C[i]*1ll*base)%P;
        base=base*1ll*1526ll%P;
    }
    printf("%d\n",ans);
    return 0;
}
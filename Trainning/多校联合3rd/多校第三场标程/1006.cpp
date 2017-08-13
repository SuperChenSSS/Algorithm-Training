#include <cstdio>
#include <cstring>
#include <algorithm>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1<<18;
const int P=998244353;
const int G=3;
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
int rev[N],w[2][N];
inline void initfft(int n){
    rep(i,0,n-1){
        int x=i;int y=0;
        for(int k=1;k<n;k<<=1,x>>=1)(y<<=1)|=(x&1);
        rev[i]=y;
    }
    int v=Pow(G,(P-1)/n);
    int dv=Pow(v,P-2);
    w[0][0]=w[1][0]=1;
    rep(i,1,n-1){
        w[0][i]=w[0][i-1]*1ll*v%P;
        w[1][i]=w[1][i-1]*1ll*dv%P;
    }
}
int fac[N],inv[N];
inline void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
    inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
}
inline void fft(int *A,int n,int ff){
    rep(i,0,n-1)if(i<rev[i])swap(A[i],A[rev[i]]);
    for(int i=1;i<n;i<<=1)
    for(int j=0,t=n/(i<<1);j<n;j+=(i<<1))
    for(int k=0,l=0;k<i;k++,l+=t){
        int x=A[i+j+k]*1ll*w[ff][l]%P;
        int y=A[j+k];
        A[j+k]=(x+y)%P;
        A[i+j+k]=(y+P-x)%P;
    }
    if(ff){
        int v=Pow(n,P-2);
        rep(i,0,n-1)A[i]=A[i]*1ll*v%P;
    }
}
int n;
int pw[N];
int ipw[N];
int A[N],B[N];
void move(int *f,int bias,int *g){
    if(bias==0){
        rep(i,0,n)g[i]=f[i];return;
    }
    //f(x)=g(x+bias)
    //f(x-bias)=g(x)
    bias=(P-bias)%P;
    //f(x+bias)=g(x)
    //f[j]->g[i]:C(j,i)*bias^(j-i)
    pw[0]=1;rep(i,1,n)pw[i]=pw[i-1]*1ll*bias%P;
    ipw[0]=1;int dj=Pow(bias,P-2);
    rep(i,1,n)ipw[i]=ipw[i-1]*1ll*dj%P;
    int m=1;
    while(m<=2*n+2)m<<=1;
    rep(i,0,m-1)A[i]=B[i]=0;
    initfft(m);
    rep(i,0,n){
        A[i]=f[i]*1ll*fac[i]%P;
    }
    rep(i,0,n){
        B[n-i]=pw[i]*1ll*inv[i]%P;
    }
    fft(A,m,0);
    fft(B,m,0);
    rep(i,0,m-1)A[i]=A[i]*1ll*B[i]%P;
    fft(A,m,1);
    rep(i,0,n)g[i]=A[i+n]*1ll*inv[i]%P;
}
int f[N],bias,ans[N],m;
void Main(){
    rep(i,0,n)read(f[i]);
    read(m);
    bias=0;
    rep(i,1,m){
        int x;read(x);bias=(bias+x)%P;
    }
    move(f,bias,ans);
    rep(i,0,n)printf("%d ",ans[i]);puts("");
}
int main(){
    init(N-1);
    while(scanf("%d",&n)!=EOF)Main();
    return 0;    
}
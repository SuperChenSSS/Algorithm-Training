#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
//const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// FFT_MAXN = 2^k
// first call fft_init() to precalc FFT_MAXN-th roots
// convo(a,n,b,m,c) a[0..n]*b[0..m] -> c[0..n+m]
typedef double db;
const int FFT_MAXN=262144,N=FFT_MAXN*2;
int mo,n;
struct cp{
	db a,b;
	cp operator+(const cp&y)const{return (cp){a+y.a,b+y.b};}
	cp operator-(const cp&y)const{return (cp){a-y.a,b-y.b};}
	cp operator*(const cp&y)const{return (cp){a*y.a-b*y.b,a*y.b+b*y.a};}
	cp operator!()const{return (cp){a,-b};};
}nw[FFT_MAXN+1];int bitrev[FFT_MAXN];
void dft(cp*a,int n,int flag=1){
	int d=0;while((1<<d)*n!=FFT_MAXN)d++;
	rep(i,0,n)if(i<(bitrev[i]>>d))swap(a[i],a[bitrev[i]>>d]);
	for (int l=2;l<=n;l<<=1){
		int del=FFT_MAXN/l*flag;
		for (int i=0;i<n;i+=l){
			cp *le=a+i,*ri=a+i+(l>>1),*w=flag==1?nw:nw+FFT_MAXN;
			rep(k,0,l>>1){
				cp ne=*ri**w;
				*ri=*le-ne,*le=*le+ne;
				le++,ri++,w+=del;
			}
		}
	}
	if(flag!=1)rep(i,0,n)a[i].a/=n,a[i].b/=n;
}
void fft_init(){
	int L=0;while((1<<L)!=FFT_MAXN)L++;
	bitrev[0]=0;rep(i,1,FFT_MAXN)bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(L-1));
	rep(i,0,FFT_MAXN+1)nw[i]=(cp){(db)cosl(2*pi/FFT_MAXN*i),(db)sinl(2*pi/FFT_MAXN*i)};
}
void convo(int*a,int n,int*b,int m,int*c){
	rep(i,0,n+m+1)c[i]=0;
	if(n<=100 && m<=100 || min(n,m)<=5){
		static int tmp[FFT_MAXN];
	//	cout<<"fft"<<endl;
	//	for (int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
	//	for (int i=0;i<m;i++) cout<<b[i]<<" "; cout<<endl;
		rep(i,0,n+m+1)tmp[i]=0;
		rep(i,0,n+1)rep(j,0,m+1)upmo(tmp[i+j],1ll*a[i]*b[j]);
		rep(i,0,n+m+1)c[i]=tmp[i];
	//	for (int i=0;i<n+m+1;i++) cout<<c[i]<<" "; cout<<endl;
		return;
	}
	static cp f[FFT_MAXN],g[FFT_MAXN],t[FFT_MAXN];
	int N=2;while(N<=n+m)N<<=1; //cout<<N<<endl;
	rep(i,0,N){
		int aa=i<=n?a[i]:0,bb=i<=m?b[i]:0;upmo(aa,0);upmo(bb,0);
		f[i]=(cp){db(aa>>15),db(aa&32767)};
		g[i]=(cp){db(bb>>15),db(bb&32767)};
	}
	dft(f,N);dft(g,N);
	rep(i,0,N){
		int j=i?N-i:0;
		t[i]=((f[i]+!f[j])*(!g[j]-g[i])+(!f[j]-f[i])*(g[i]+!g[j]))*(cp){0,0.25};
	}
	dft(t,N,-1);
	rep(i,0,n+m+1)upmo(c[i],(ll(t[i].a+0.5))%mo<<15);
	rep(i,0,N){
		int j=i?N-i:0;
		t[i]=(!f[j]-f[i])*(!g[j]-g[i])*(cp){-0.25,0}+(cp){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
	}
	dft(t,N,-1);
	rep(i,0,n+m+1)upmo(c[i],ll(t[i].a+0.5)+(ll(t[i].b+0.5)%mo<<30));
}
int size=100;
int I[N+10],nI[N+10],w[N+10],phi[N+10],prime[N],len;
void make(){
	phi[1]=1;
	for (int i=2;i<=N;i++){
		if (phi[i]==0){
			phi[i]=i-1; prime[++len]=i;
		}
		for (int j=1;prime[j]*i<=N&&j<=len;j++)
			if (i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j]; break;
			} else phi[i*prime[j]]=phi[i]*(prime[j]-1);
	}
}
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int C(int k1,int k2){
	return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int a[N+10],b[N+10],c[N*2+10]; 
void solve(){
	scanf("%d%d",&n,&mo); I[0]=1; if (n<=10000) size=25; else size=65;
	assert(1<=n&&n<=100000); assert(100000000<=mo&&mo<=1000000000);
	for (int i=2;i*i<=mo;i++) assert(mo%i>0);
	for (int i=1;i<=n;i++) I[i]=1ll*I[i-1]*i%mo;
	nI[n]=quick(I[n],mo-2); int ans=0;
	for (int i=n;i;i--) nI[i-1]=1ll*nI[i]*i%mo;
	for (int now=1;now<=n;now++){
		int N=n/now;
		for (int i=0;i<=N;i++) a[i]=1ll*nI[i*now],b[i]=a[i];
		convo(a,N,b,N,c);
		int num=0;
		for (int i=0;i<=N;i++) num=(num+1ll*c[i]*nI[n-i*now])%mo;
		ans=(ans+1ll*num*phi[now]%mo*I[n])%mo;
	}
	for (int i=1;i<=n;i++) ans=(ans-phi[i]+mo)%mo;
	ans=1ll*ans*quick(3,n)%mo;
	printf("%d\n",ans);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	make(); fft_init();
//	for (int i=1;i<=10;i++) cout<<phi[i]<<" "; cout<<endl;
	int t; scanf("%d",&t); assert(1<=t&&t<=20);
	for (;t;t--) solve();
	return 0;
}

#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define mp std::make_pair
#define sz size()
#define fi first
#define se second
#define ll long long
#define ld long double
#define mo 1000000007
#define P 32677
#define P1 41
#define P2 797
#define M 524293
void NT(int p,int&r,int*ex,int*lg){
	r=2;
	while(1){
		rep(i,1,p-1) lg[i]=0;
		ex[0]=1;
		rep(i,1,p-1){
			ex[i]=ex[i-1]*r%p;
			if(lg[ex[i]]){
				ex[0]=-1;break;
			}
			lg[ex[i]]=i;
		}
		if(ex[0]==1) break;
		r++;
	}
	lg[1]=0;
}
int r1,ex1[P1],lg1[P1];
int r2,ex2[P2],lg2[P2];
void init(){
	NT(P1,r1,ex1,lg1);
	NT(P2,r2,ex2,lg2);
}
namespace FFT{
	struct Z{
		ld x,y;
		Z(){x=y=0;}
		Z(ld X,ld Y){x=X;y=Y;}
	}T[M];int m;
	Z operator+(Z a,Z b){return Z(a.x+b.x,a.y+b.y);}
	Z operator-(Z a,Z b){return Z(a.x-b.x,a.y-b.y);}
	Z operator*(Z a,Z b){return Z(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	const ld pi=acos(-1.0);
	void Init(int _m){
		m=_m;
		rep(i,0,m) T[i]=Z(cos(pi*2/m*i),sin(pi*2/m*i));
	}
	void dft(Z*a,int n,int d){
		for(int i=(n>>1),j=1,k;j<n;j++){
			if(i<j){Z t=a[i];a[i]=a[j];a[j]=t;}
			for(k=(n>>1);i&k;i^=k,k>>=1);i^=k;
		}
		for(int k=2;k<=n;k<<=1) for(int i=0;i<n;i+=k) for(int j=i;j<(i+(k>>1));j++){
			Z t=T[d==1?(j-i)*(m/k):m-(j-i)*(m/k)],u=a[j],v=t*a[j+(k>>1)];
			a[j]=u+v;a[j+(k>>1)]=u-v;
		}
	}
	Z ta[M],tb[M];
	void conv(int n,int*a,int*b,ll*c){
		for(int i=0;i<n;i++) ta[i]=(Z){a[i],0},tb[i]=(Z){b[i],0};
		dft(ta,n,1);dft(tb,n,1);
		for(int i=0;i<n;i++) ta[i]=ta[i]*tb[i];
		dft(ta,n,-1);
		for(int i=0;i<n;i++) c[i]=(long long)(ta[i].x/n+0.5);
	}
}
int T,n,x,a[P1][P2],f[M];ll g[M];
ll t,b[P1][P2];int c[P];
void Dconv(){
	memset(f,0,sizeof(f));
	rep(i,1,P1-1) rep(j,1,P2-1) f[lg1[i]*P2*2+lg2[j]]=a[i][j];
	int L=1;while(L<4*P) L<<=1;
	FFT::Init(L);FFT::conv(L,f,f,g);
	rep(i,0,L-1) b[ex1[i/(P2*2)%(P1-1)]][ex2[i%(P2*2)%(P2-1)]]+=g[i];
}
namespace Task{
	int tot,p[P],vis[P],d[P];
	unsigned s[P],ans,mu[P];
	std::vector<std::pair<int,unsigned> > e[P];
	void euler(int n){
		mu[1]=1;tot=0;
		rep(i,1,n) vis[i]=0;
		rep(i,2,n){
			if(!vis[i]) p[++tot]=i,mu[i]=-1;
			rep(j,1,tot){
				if(i*p[j]>n) break;
				vis[i*p[j]]=1;
				if(i%p[j]==0){
					mu[i*p[j]]=0;
					break;
				}
				else mu[i*p[j]]=-mu[i];
			}
		}
	}
	int solve(int n,int*a){
		euler(n);
		ans=3*a[0]*a[1]*a[1];
		rep(i,1,n) s[i]=0;
		rep(i,1,n) for(int j=i;j<=n;j+=i) s[i]+=a[j];
		rep(i,1,n) ans+=mu[i]*mu[i]*mu[i]*s[i]*s[i]*s[i];
		rep(gcd,1,n) for(int lcm=gcd;lcm<=n;lcm+=gcd) if(mu[lcm]){
			int m=lcm/gcd;
			for(int j=1;j*j<=m;j++) if(m%j==0){
				int x=j*gcd,y=m/j*gcd;
				if(x>=y) continue;
				d[x]++;d[y]++;
				ans+=3*mu[x]*mu[x]*mu[y]*s[x]*s[lcm]*s[lcm];
				ans+=3*mu[y]*mu[y]*mu[x]*s[y]*s[lcm]*s[lcm];
			}
		}
		rep(i,1,n) e[i].clear();
		rep(gcd,1,n) for(int lcm=gcd;lcm<=n;lcm+=gcd) if(mu[lcm]){
			int m=lcm/gcd;
			for(int j=1;j*j<=m;j++) if(m%j==0){
				int x=j*gcd,y=m/j*gcd;
				if(x>=y) continue;
				if(d[x]>d[y]) std::swap(x,y);
				e[x].pb(mp(y,s[lcm]));
			}
		}
		rep(i,1,n) sort(e[i].begin(),e[i].end());
		rep(i,1,n) rep(j,1,e[i].sz){
			int k=e[i][j-1].fi,p1=0,p2=0;
			while(p1<e[i].sz&&p2<e[k].sz){
				if(e[i][p1].fi==e[k][p2].fi){
					ans+=6*mu[i]*mu[k]*mu[e[i][p1].fi]*
					e[i][p1].se*e[k][p2].se*e[i][j-1].se;
					p1++;p2++;
				}
				else if(e[i][p1].fi<e[k][p2].fi) p1++;
				else p2++;
			}
		}
		return ans%(1<<30);
	}
}
void solve(){
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	rep(i,1,n) scanf("%d",&x),a[x%P1][x%P2]++;
	memset(b,0,sizeof(b));
	rep(i,0,P1-1){
		ll t=-a[i][0];
		rep(j,0,P2-1) t+=a[i][j]*2;
		rep(j,0,P1-1) b[i*j%P1][0]+=t*a[j][0];
	}
	rep(i,1,P2-1){
		ll t=-a[0][i];
		rep(j,0,P1-1) t+=a[j][i]*2;
		rep(j,1,P2-1) b[0][i*j%P2]+=t*a[0][j];
	}
	Dconv();
	rep(i,0,P-1) c[i]=b[i%P1][i%P2]%(1<<30);
	printf("%d\n",Task::solve(P-1,c));
}
int main(){
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	init();
	scanf("%d",&T);
	while(T--) solve();
}

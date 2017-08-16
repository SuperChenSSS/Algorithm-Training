#include <cstdio>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define mo 998244353
#define N 1005
int T,n,m,x;char tmp[N];
int rowtag[N],coltag[N],rows,cols,alltag;
int dt,ans;
int main(){
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n) rowtag[i]=0;rows=n;
		rep(i,1,m) coltag[i]=0;cols=m;
		alltag=0;
		rep(i,1,n){
			scanf("%s",tmp+1);
			rep(j,1,m) if(tmp[j]!='?'){
				x=tmp[j]=='R';x++;
				if(i+j&1) x=3-x;
				if(rowtag[i]==3-x) rows=-1;else if(!rowtag[i]) rowtag[i]=x,rows--;
				if(coltag[j]==3-x) cols=-1;else if(!coltag[j]) coltag[j]=x,cols--;
				if(alltag>=0) if(alltag==3-x) alltag=-1;else alltag=x;
			}
		}
		ans=0;
		if(rows>=0){
			dt=1;while(rows--) dt=dt*2%mo;
			ans=(ans+dt)%mo;
		}
		if(cols>=0){
			dt=1;while(cols--) dt=dt*2%mo;
			ans=(ans+dt)%mo;
		}
		if(alltag>=0){
			dt=alltag?1:2;
			ans=(ans-dt+mo)%mo;
		}
		printf("%d\n",ans);
	}
}

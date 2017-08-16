#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define MOD 9875321
#define N 120005
struct hashtable{
	int a[MOD];
	void clr(){
		for(int i=0;i<MOD;i++) a[i]=-1;
	}
	void ins(int x){
		int t=x%MOD;
		while(a[t]!=-1&&a[t]!=x) if(++t==MOD) t=0;
		a[t]=x;
	}
	bool exs(int x){
		int t=x%MOD;
		while(a[t]!=-1&&a[t]!=x) if(++t==MOD) t=0;
		return a[t]==x;
	}
}_;
int par(int x,int y){
	return x<y?(y*(y-1)>>1)+x:(x*(x-1)>>1)+y;
}
int T,n,m,nn,u,v,x[N],y[N],s[N/2],e[N*2],d[N/2];
long long ans;
int main(){
	//freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rpt(i,1,m) scanf("%d%d",&x[i],&y[i]);
		nn=n+1>>1;
		rpt(i,0,nn) s[i]=0;
		rpt(i,1,m) s[x[i]]++,x[i]!=y[i]?s[y[i]]++:0;
		rpt(i,1,nn) s[i]+=s[i-1];
		rpd(i,nn,1) s[i]=s[i-1];
		rpt(i,1,m) e[++s[x[i]]]=y[i],x[i]!=y[i]?e[++s[y[i]]]=x[i]:0;
		_.clr();
		rpt(i,1,m) _.ins(par(x[i],y[i]));
		ans=1LL*n*n*n;
		rpt(i,1,nn) d[i]=0;
		rpt(i,1,m) d[x[i]]+=n&1?(y[i]!=nn)+1:2,x[i]!=y[i]?d[y[i]]+=n&1?(x[i]!=nn)+1:2:0;
		rpt(i,1,nn) ans-=1LL*(d[i])*(n-d[i])*3*(n&1?(i!=nn)+1:2);
		rpt(i,1,nn) rpt(j,s[i-1]+1,s[i]){
			if(s[i]-s[i-1]<s[e[j]]-s[e[j]-1]) u=i,v=e[j];else u=e[j],v=i;
			rpt(k,s[u-1]+1,s[u]) if(_.exs(par(v,e[k]))) ans-=n&1?((u!=nn)+1)*((v!=nn)+1)*((e[k]!=nn)+1):8;
		}
		printf("%lld\n",ans);
	}
}

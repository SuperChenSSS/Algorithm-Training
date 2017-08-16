#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
int T,m,n,p,k,x;
int in[16],s[32768],f[32768][16];
int prod[16],t,d,ans,tmp;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	freopen("L.in","r",stdin);
	freopen("L.out","w",stdout);
  scanf("%d",&T);
  while(T--){
	scanf("%d%d%d",&m,&n,&p);
	rpt(i,1,m) in[i]=1<<(i-1);
	rpt(i,1,m){
		scanf("%d",&k);while(k--) scanf("%d",&x),in[i]|=1<<(x-1);
		scanf("%d",&k);while(k--) scanf("%d",&x),in[x]|=1<<(i-1);
	}
	rpt(i,0,(1<<m)-1){
		s[i]=0;
		rpt(j,1,m) if(i&(1<<(j-1))) s[i]|=in[j];
	}
	rpt(i,0,(1<<m)-1){
		f[i][0]=!i;
		rpt(j,1,m) f[i][j]=0;
		x=i;
		while(x){
			if((i&s[x])==s[x]) rpt(j,1,m){
				f[i][j]+=f[i^x][j-1];
				if(f[i][j]>=p) f[i][j]-=p;
			}
			x=(x-1)&i;
		}
	}
	ans=0;
	rpt(i,1,m){
		prod[i]=n-i+1;t=i;
		rpt(j,1,i){
			d=gcd(prod[j],t);
			prod[j]/=d;t/=d;
		}
		tmp=f[(1<<m)-1][i];
		rpt(j,1,i) tmp=1LL*tmp*prod[j]%p;
		ans+=tmp;if(ans>=p) ans-=p;
	}
	printf("%d\n",ans);
  }
}

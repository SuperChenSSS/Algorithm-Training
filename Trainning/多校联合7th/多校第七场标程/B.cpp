#include <cstdio>
#define xo(a,b) ((b)&1?(a):0)
int T,a;
long long b[60],s[60],f[60];
long long n,k;
long long solve(long long x,int y){
	return y?(x+s[y])^xo(f[y],x/b[y-1])^xo(f[y-1],k^(x/b[y-1])^1)^solve(x%b[y-1],y-1):0;
}
int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		if(k>1){
			b[0]=1;s[0]=f[0]=a=0;
			while((n-1)/k>=s[a]) a++,b[a]=b[a-1]*k,s[a]=s[a-1]+b[a-1],f[a]=s[a]^xo(f[a-1],k);
			printf("%lld\n",solve(n-s[a],a));
		}
		else printf("%lld\n",n%4==1?1:(n%4==2?n+1:(n%4==3?0:n)));
	}
}

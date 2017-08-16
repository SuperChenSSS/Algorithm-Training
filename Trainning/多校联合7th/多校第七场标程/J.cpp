#include <cstdio>
int T,n,m,k,a[200005];
int main(){
	freopen("J.in","r",stdin);
	freopen("J.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		k=1;m--;
		while(k<n){
			for(int i=n;i>k;i--) a[i]^=m&1?0:a[i-k];
			m>>=1;k<<=1;
		}
		for(int i=1;i<=n;i++) printf(i<n?"%d ":"%d\n",a[i]);
	}
}

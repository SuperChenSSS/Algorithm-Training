#include<cstdio>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 1000005
int T,n;
int main(){
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",n+3>>1);
	}
}

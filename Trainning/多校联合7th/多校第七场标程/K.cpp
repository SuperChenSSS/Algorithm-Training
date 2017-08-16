#include <cstdio>
int k[10000005],a,i,j,ii,T,n;
int main(){
	freopen("K.in","r",stdin);
	freopen("K.out","w",stdout);
	k[1]=a=1;k[2]=k[3]=2;i=3;j=4;
	while(j<=10000000){
		for(ii=1;ii<=k[i];ii++) k[j++]=a;
		i++;a=3-a;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",k[n]);
	}
}

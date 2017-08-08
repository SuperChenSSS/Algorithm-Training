#include<iostream>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long m;
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=10); 
	for (;t;t--){
		scanf("%d%lld",&n,&m); assert(1<=n&&n<=1000000&&1<=m&&m<=1000000000000ll);
		if (m<=n-1){
			int k1=m+1,k2=0;
			long long ans=(k1-1)*2+2ll*(k1-1)*(k1-2)+(1ll*n*(n-1)-1ll*k1*(k1-1))*n;
			printf("%lld\n",ans);
		} else {
			m=min(m,1ll*n*(n-1)/2);
			long long ans=1ll*n*(n-1)*2-m*2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}

#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
long long B[11000];
int n,m;
void solve(){
	scanf("%d%d",&n,&m); assert(1<=n&&n<=50&&1<=m&&m<=10000);
	for (int i=0;i<=m;i++) scanf("%lld",&B[i]);
	for (;n;n--){
		int num=0; int where=0;
		for (int i=1;i<=m;i++) if (B[i]) {where=i; break;}
		printf("%d",where); if (n==1) printf("\n"); else printf(" ");
		for (int i=where;i<=m;i++) B[i]-=B[i-where];
	}
	assert(B[0]==1);
	for (int i=1;i<=m;i++) assert(B[i]==0);
	return;
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=70);
	for (;t;t--) solve();
	return 0;
}

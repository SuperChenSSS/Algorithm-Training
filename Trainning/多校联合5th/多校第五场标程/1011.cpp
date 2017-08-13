#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
int n,K,A[110000];
void solve(){
	scanf("%d%d",&n,&K); assert(1<=n&&n<=100000&&0<=K&&K<1000000000);
	for (int i=1;i<=n;i++){
		scanf("%d",&A[i]); assert(1<=A[i]&&A[i]<=1000000000);
	}
	sort(A+1,A+n+1); int ans=n;
	for (int i=n;i>1;i--)
		if (A[i]-A[i-1]>K){
			ans=n-i+1; break;
		}
	printf("%d\n",ans);
}
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=100);
	for (;t;t--) solve();
	return 0;
}

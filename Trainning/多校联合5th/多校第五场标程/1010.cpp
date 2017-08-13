#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
int A[41000][5],B[41000][5];
long long dp[2][16];
int f[2][16],n,m,K;
inline void update(long long &k1,int &k2,long long k3,int k4){
//	cout<<"update "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl; int kk; cin>>kk;
	if (k3<k1){
		k1=k3; k2=k4;
	} else if (k3==k1) k2=max(k2,k4);
}
pair<int,long long>calc(long long w){
	memset(f,0x00,sizeof f); memset(dp,0x00,sizeof dp); 
	int now=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int ne=now^1;
			memset(dp[ne],0x00,sizeof dp[ne]);
			for (int k=0;k<(1<<m);k++){
				if (j>1&&(k&(1<<j-2))==0) update(dp[ne][k|(1<<j-1)|(1<<j-2)],f[ne][k|(1<<j-1)|(1<<j-2)],dp[now][k]+B[i][j-1]-w,f[now][k]+1);
				if (i>1&&(k&(1<<j-1))==0) update(dp[ne][k|(1<<j-1)],f[ne][k|(1<<j-1)],dp[now][k]+A[i-1][j]-w,f[now][k]+1);
				if (k&(1<<j-1)) update(dp[ne][k-(1<<j-1)],f[ne][k-(1<<j-1)],dp[now][k],f[now][k]);
				else update(dp[ne][k],f[ne][k],dp[now][k],f[now][k]);
			}
			now=ne;
		}
	int way=0; long long ans=1e18;
	for (int i=0;i<(1<<m);i++)
		update(ans,way,dp[now][i],f[now][i]);
//	cout<<w<<" "<<ans<<" "<<way<<endl; 
	return make_pair(way,ans);
}
void solve(int t){
	scanf("%d%d%d",&n,&m,&K); assert(1<=n&&n<=40000&&1<=m&&m<=4&&1<=K&&K<=(n*m)/2);
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++){
			scanf("%d",&A[i][j]); assert(1<=A[i][j]&&A[i][j]<=1000000000);
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++){
			scanf("%d",&B[i][j]); assert(1<=B[i][j]&&B[i][j]<=1000000000);
		}
	long long l=0,r=1e14,ans=0;
	while (l<r){
		long long mid=l+r>>1;
		if (calc(mid).first>=K){
			r=mid; ans=mid;
		} else l=mid+1;
	}
	pair<int,long long>now=calc(ans);
	printf("%lld\n",now.second+1ll*K*ans);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=1000);
	for (int i=1;i<=t;i++) solve(i);
	return 0;
}

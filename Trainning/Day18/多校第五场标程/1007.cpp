#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
struct bian{
	int next,point;
}b[110000];
const int mo=998244353;
int f[50010][210],g[50010][210],p[51000],len,n,m,size[51000];
int A[410],B[410];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void merge(int k1,int k2){
	/*cout<<"merge "<<k1<<" "<<k2<<" "<<size[k1]<<" "<<size[k2]<<endl;
	for (int i=0;i<m;i++) cout<<f[k1][i]<<" "; cout<<endl;
	for (int i=0;i<m;i++) cout<<g[k1][i]<<" "; cout<<endl;
	for (int i=0;i<m;i++) cout<<f[k2][i]<<" "; cout<<endl;
	for (int i=0;i<m;i++) cout<<g[k2][i]<<" "; cout<<endl;*/
	memset(A,0x00,sizeof A);
	memset(B,0x00,sizeof B); long long w,tot;
	for (int i=0;i<=size[k1];i++)
		for (int j=0;j<=size[k2];j++){
			w=1ll*f[k1][i]*g[k2][j]; tot=f[k2][j]+g[k2][j];
			A[i+j]=(A[i+j]+w+tot*f[k1][i])%mo;
			B[i+j]=(B[i+j]+(f[k1][i]+g[k1][i])*tot-w+tot*g[k1][i])%mo;
		}
	for (int i=0;i<m;i++){
		f[k1][i]=(A[i]+A[i+m])%mo; g[k1][i]=(B[i]+B[i+m])%mo;
	}
	size[k1]=min(size[k1]+size[k2],m-1);
}
void treedp(int k1,int k2){
	size[k1]=0; memset(f[k1],0x00,sizeof f[k1]);
	memset(g[k1],0x00,sizeof g[k1]); f[k1][0]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp(j,k1); merge(k1,j);
		}
	}
	size[k1]=min(size[k1]+1,m-1); int pre=f[k1][m-1];
	for (int i=m-1;i;i--) f[k1][i]=f[k1][i-1];
	f[k1][0]=pre;
//	cout<<"fa "<<k1<<endl;
//	for (int i=0;i<m;i++) cout<<f[k1][i]<<" "; cout<<endl;
//	for (int i=0;i<m;i++) cout<<g[k1][i]<<" "; cout<<endl;
}
int father[51000];
int findfather(int k1){
	if (father[k1]==k1) return k1; return father[k1]=findfather(father[k1]);
}
void solve(){
	scanf("%d%d",&n,&m); memset(p,0x00,sizeof p); len=0;
	assert(1<=n&&n<=50000&&1<=m&&m<=200);
	for (int i=1;i<=n;i++) father[i]=i; int num=0;
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
		if (findfather(k1)!=findfather(k2)){
			num++; father[findfather(k1)]=findfather(k2);
		}
	}
	assert(num==n-1);
	treedp(1,0); printf("%d\n",(f[1][n%m]+g[1][n%m])%mo);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=100);
	for (;t;t--) solve();
	return 0;
}


#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
using namespace std;
const int size=1000;
unsigned int A[32][11000],B[11000],ans[11000];
void set(unsigned int *A,int k2){
	A[k2>>5]^=(1<<(k2&31));
}
int get(unsigned int *A,int k2){
	return (A[k2>>5]>>(k2&31))&1;
}
void addin(int l,int r){
	while ((r-l)&31){
		r--; if (get(A[0],r)) set(ans,r-l);
	}
	int where=0;
	while (l&31) l++,r++,where++;
	l>>=5; r>>=5;
	for (int i=l;i<r;i++) ans[i-l]^=A[where][i];
}
int n,m,N,M,q,pd[51000];
void solve(){
	scanf("%d%d%d",&N,&M,&q); memset(pd,0x00,sizeof pd);
	assert(1<=N&&N<=50000&&1<=M&&M<=50000&&1<=q&&q<=50000);
	memset(A,0x00,sizeof A); memset(B,0x00,sizeof B); 
	n=m=0; memset(ans,0x00,sizeof ans);
	for (int i=1;i<=N;i++){
		int k1; scanf("%d",&k1); assert(pd[k1]==0); pd[k1]=1;
		for (int j=0;j<32;j++) set(A[j],k1+j);
		n=max(n,k1);
	}
	memset(pd,0x00,sizeof pd);
	for (int i=1;i<=M;i++){
		int k1; scanf("%d",&k1); set(B,k1); m=max(m,k1);
		assert(pd[k1]==0); pd[k1]=1;
	}
	for (int i=1;i<=m;i++)
		if (get(B,i))
			for (int j=0;j<=n;j+=i)
				addin(j,min(n+1,j+i));
	for (;q;q--){
		int k1; scanf("%d",&k1); assert(0<=k1&&k1<m);
		printf("%d\n",(int)get(ans,k1));
	}
}
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data1.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=5);
	for (;t;t--) solve();
	return 0;
}

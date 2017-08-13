#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[5100];
double L[5100];
const int N=5000,mo=998244353;
int I[5100],A[5100],B[5100],len,C[5100],Le,pd[5100],tt;
void change(int len,int m){
	Le=0; memcpy(B,A,sizeof A);
	while (len){
		int x=0;
		for (int i=len;i;i--){
			int pre=x; x=(x*10+B[i])%m; B[i]=(pre*10+B[i])/m;
		}
		C[++Le]=x; while (len&&B[len]==0) len--;
	}
}
int calc(int m){
	change(len,m);
	if (Le>m) return (I[m]-I[m-1]+mo)%mo;
	if (Le<m) return 0;
	for (int i=0;i<m;i++) pd[i]=0; 
	int ans=0;
	for (int i=1;i<C[Le];i++) ans=(ans+I[Le-1])%mo;
	pd[C[Le]]=1;
	for (int i=Le-1;i;i--){
		for (int j=0;j<C[i];j++) if (pd[j]==0) ans=(ans+I[i-1])%mo;
		if (pd[C[i]]) break; pd[C[i]]=1;
		if (i==1) ans=(ans+1)%mo; 
	}
//	cout<<ans<<endl;
	return ans;
}
int calc(){
//	cout<<"start calc"<<endl; cout<<L[9]<<endl;
//	for (int i=1;i<=len;i++) cout<<A[i]<<" "; cout<<endl;
	if (len==0) return 0;
	int ans=0,where=2;
	while (L[where]<=len-1) where++;
	if (where<=15){
		for (int i=2;i<=15;i++) ans=(ans+calc(i))%mo;
		return ans;
	}
	for (int i=2;i<=where-2;i++) ans=((ans+I[i]-I[i-1])%mo+mo)%mo;
	ans=(ans+1ll*calc(where-1)+calc(where))%mo;
	return ans;
}
int x[5100],y[5100],lenx,leny;
int checkbig(){
	if (lenx<leny) return 1; else if (lenx>leny) return 0;
	for (int i=1;i<=lenx;i++)
		if (x[i]<y[i]) return 1; else if (x[i]>y[i]) return 0;
	return 1;
}
void solve(){
	scanf("%s",ch+1); len=strlen(ch+1); assert(1<=len&&len<=5000&&ch[1]!='0');
	for (int i=1;i<=len;i++) A[i]=ch[len-i+1]-'0';
	lenx=len; for (int i=1;i<=len;i++) x[i]=A[i];
	A[1]--;
	for (int i=1;i<=len;i++)
		if (A[i]<0){
			A[i+1]--; A[i]+=10;
		}
	while (len&&A[len]==0) len--;
	int ans=calc(); //cout<<ans<<" ";
	scanf("%s",ch+1); len=strlen(ch+1); assert(1<=len&&len<=5000&&ch[1]!='0');
	for (int i=1;i<=len;i++) A[i]=ch[len-i+1]-'0';
	leny=len; for (int i=1;i<=len;i++) y[i]=A[i];
	assert(checkbig());
	ans=(calc()-ans+mo)%mo;
	printf("%d\n",ans);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	len=1;
	while (L[len]<=N){
		len++; L[len]=log(len)/log(10)*(len-1);
	}
//	for (int i=1;i<=20;i++) cout<<L[i]<<" "; cout<<endl;
	I[0]=1; for (int i=1;i<=N;i++) I[i]=1ll*I[i-1]*i%mo;
	int t; scanf("%d",&t); assert(1<=t&&t<=20);
	for (;t;t--){tt++; solve();}
	return 0;
}

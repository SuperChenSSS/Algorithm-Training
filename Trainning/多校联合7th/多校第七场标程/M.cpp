#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
#define w1 first
#define ls (x<<1)
#define w2 second
#define ins insert
#define rs (x<<1|1) 
#define mp make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define cle(x) ((x).clear())
#define lowbit(x) ((x)&(-x))
#define SZ(x) (int((x).size()))
#define ms(x,y) memset(x,y,sizeof (x))
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)]) 
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=nxt[(p)])
template<class T>inline void rread(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
//********************************head*************************************
inline int power(int x,ll k,int p){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%p)if(k&1)res=1ll*res*x%p;
	return res;
}
const int maxn=10+5,maxp=5e2+5,mod=1e9+7;
ll h;
int x,y,p,per,st;
int level[maxp][maxp],cnt[maxp],F[maxp][maxn][maxp],Binom[maxp][maxn];
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int sub(int x,int y){
	return x-y<0?x-y+mod:x-y;
}
inline void upd(int &x,int y){
	x=add(x,y);
}
inline int calc(ll a,int p){
	if(a<0)return 0;
	int inv=power(sub(power(2,p,mod),1),mod-2,mod);
	int res=sub(power(2,a+p,mod),power(2,a%p,mod));
	return 1ll*res*inv%mod;
}
inline int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	int res=1;
	rep(i,1,m){
		res=1ll*res*n%mod*power(i,mod-2,mod)%mod;
		n--;
	}
	return res;
}
int main(){
	freopen("M.in","r",stdin);
	freopen("M.out","w",stdout);
  int T;rread(T);
  while(T--){
	rread(h);rread(x);rread(y);rread(p);
	x%=p;
	int Last=0,B=x,Now=0;per=0;st=0;
	memset(level,0,sizeof(level));
	memset(cnt,0,sizeof(cnt));
	memset(F,0,sizeof(F));
	rep(i,1,h){
		Now=(2*Last+B)%p;
		if(level[Last][Now]){
			st=i;
			per=i-level[Last][Now];
			break;
		}
		B=B*x%p;
		level[Last][Now]=i;
		Last=Now;
		upd(cnt[Now],power(2,h-i,mod));
	}
	if(st){
		rep2(i,0,per){
			Now=(2*Last+B)%p;
			upd(cnt[Now],calc(h-(st+i),per));
			B=B*x%p;
			Last=Now;
		}
	}
	rep2(i,0,p)rep(j,0,y)Binom[i][j]=C(sub(add(j,cnt[i]),1),j);
	rep(i,0,y)F[0][i][0]=Binom[0][i];

	rep(lastB,0,p-2)rep(lastC,0,y)rep(lastSum,0,p-1)if(F[lastB][lastC][lastSum]){
		rep(now,0,y)if(now+lastC<=y){
			int nxtB=lastB+1,nxtC=lastC+now,nxtSum=(lastSum+now*nxtB)%p;
			upd(F[nxtB][nxtC][nxtSum],1ll*F[lastB][lastC][lastSum]*Binom[nxtB][now]%mod);
		}
	}
	int ans=0;
	rep(i,0,y)upd(ans,F[p-1][i][0]);
	printf("%d\n",ans);
  }
}

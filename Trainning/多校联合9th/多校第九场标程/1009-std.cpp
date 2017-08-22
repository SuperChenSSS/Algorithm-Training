#include <bits/stdc++.h>

#define LL long long
#define LD double
#define FOR(i,a,b) for (int i = (a);i <= (b); i++)
#define DFOR(i,a,b) for (int i = (a);i >= (b); i--)
#define debug(x) cerr << "debug: " << (#x) << " = " << (x) <<endl;
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define itr iterator
#define bit(x) (1LL<<(x))
#define lb(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
#define gn 3
#define l(x) ch[x][0]
#define r(x) ch[x][1]
#define y0 Y0
#define y1 Y1
#define y2 Y2
#define fir first
#define sec second

using namespace std;

const int N = 320000, NN = 10010, MM = 110;
const LL P = 1000000007LL;

int tot,prime[N],tim;
bool v[N];
LL f[NN][MM],inv2;

LL qpow(LL x,LL n){
	LL ans=1;
	for(;n;n>>=1,x = x*x%P) if(n&1) ans=ans*x%P;
	return ans;
}

LL S(LL n,int m){
	if(n==1) return 1ll;
	if(n==0) return 0ll;
	if(m==0) return n%P*(n%P+1)%P * inv2%P;
	if(n<NN && m<MM) return f[n][m];
	if(m && prime[m]>n){
		while(m && prime[m]>n) m--;
		return S(n,m);
    }
	return (S(n,m-1) + P - prime[m]*(LL)S(n/prime[m], m-1)%P) % P;
}

bool isprime(LL n){
	if(n==2) return 1;
	for(int i=2;1ll*i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}

int main(){
	FOR(i,2,N-1) if(!v[i]){
		prime[++tot] = i;
		for(int j=i+i;j<N;j+=i) v[j] = 1;
	}
	FOR(i,1,NN-1){
		f[i][0] = (1ll*i*(i+1)/2) % P;
		FOR(j,1,MM-1) f[i][j] = (f[i][j-1] + P - prime[j]*(LL)f[i/prime[j]][j-1]%P) % P;
	}
	inv2 = qpow(2,P-2);
	int T,Te = 0;
	cin>>T;
	while(T--){
		LL L,R,K;
		cin>>L>>R>>K;
		printf("Case #%d: ",++Te);
		if(!isprime(K)) cout<<0<<endl;
		else if(K>N){
			if(K<=R && K>=L) cout<<K%P<<endl;
			else cout<<0<<endl;
		}else{
			int tmp = 0;
			while(prime[tmp+1]<K) tmp++;
			cout << (S(R/K,tmp)*K%P - S((L-1)/K,tmp)*K%P + P) % P << endl;
		}
	}
	return 0;
}

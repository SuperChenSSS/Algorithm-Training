#include <iostream>  
#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
typedef long long ll;  
using namespace std;  
const int maxn=1e6+10;  
const int mod=998244353;  
int tot,t;  
ll l,r,k,ans,cnt[maxn],q[maxn],primes[maxn];  
bool vis[maxn];  
void init(){  
	for(int i=2;i<maxn;i++){  
		if(!vis[i])  
			primes[tot++]=i;  
		for(int j=0;j<tot;j++){  
			int k=i*primes[j];  
			if(k>maxn)break;  
			vis[k]=1;  
		}  
	}  
}  
int main(){  
	scanf("%d",&t);  
	init();  
	while(t--){  
		scanf("%lld%lld%lld",&l,&r,&k);  
		ans=0;  
		if(l==1) ans++,l++;  
		for(ll i=0;i<=r-l;i++) cnt[i]=1,q[i]=l+i;  
		for(ll i=0;primes[i]*primes[i]<=r;i++){  
			ll j=l/primes[i]+(l%primes[i]!=0);  
			for(j=j*primes[i];j<=r;j+=primes[i]){  
				ll tmp=0;  
				while(q[j-l]%primes[i]==0) q[j-l]/=primes[i],tmp++;  
				cnt[j-l]*=(tmp*k)%mod+1,cnt[j-l]%=mod;  
			}  
		}  
		for(ll i=0;i<=r-l;i++){  
			if(q[i]!=1) ans+=((k+1)*cnt[i])%mod;  
			else        ans+=cnt[i];  
			ans%=mod;  
		}  
		printf("%lld\n",ans);  
	}  
} 
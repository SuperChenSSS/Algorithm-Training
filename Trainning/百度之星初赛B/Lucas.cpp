//解决C(n,m) % p的算法
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
typedef long long LL;  
LL Power_mod(LL a, LL b, LL p)  
{  
	LL res = 1;  
	while(b!=0)  
	{  
		if(b&1) res = (res*a)%p;  
		a = (a*a)%p;  
		b >>= 1;  
	}  
	return res;  
}  
LL Comb(LL a,LL b, LL p)  
{  
	if(a < b) return 0;  
	if(a == b) return 1;  
	if(b > a-b) b = a-b;  
	LL ans = 1, ca = 1, cb = 1;  
	for(LL i=0; i<b; ++i)  
	{  
		ca = (ca*(a-i))%p;  
		cb = (cb*(b-i))%p;  
	}  
	ans = (ca*Power_mod(cb, p-2, p))%p;  
	return ans;  
}  
LL Lucas(int n, int m, int p)  
{  
	LL ans = 1;  
	while(n && m && ans)  
	{  
		ans = (ans * Comb(n%p, m%p, p))%p;  
		n /= p;  
		m /= p;  
	}  
	return ans;  
}  
int main()  
{  
	int n,m,p;  
	while(scanf("%d%d%d",&n,&m,&p) !=EOF)  
	{  
		printf("%lld\n",Lucas(n,m,p));  
	}  
	return 0;  
}  
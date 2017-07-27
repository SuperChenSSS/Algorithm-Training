//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue>  
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int MOD = 1e9+7;  
const int maxn = 1e6;


long long pow_mod(long long a,long long i,long long n)
{
	if(i == 0) return 1%n;
	int temp = pow_mod(a,i>>1,n);
	temp = temp*temp%n;
	if(i&1) temp =(long long)temp*a%n;
	return temp; 
}

int main()
{
	int T,k;
	long long t1,t2;
	long long N,M;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&N,&M);
		if(N&1) k = 1;
		else k = 0;
		t1 = pow_mod(2, N, MOD)-1;
		t2 = pow_mod(t1, M-1, MOD);
		t2 = (t2*2 + k)%MOD;
		t2 = t2/3;
		t2 = t2%MOD;
		printf("%lld\n",t2);
	}
	return 0;
}
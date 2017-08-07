#include <algorithm> //TDteam01
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>

const int maxn = 1e6;

using namespace std;
int T;
int a[maxn],b[maxn],tot;
long long l,r,k;


void factor(long long n)
{
	int temp,i,now;
	temp = (int)((double)sqrt(n)+1);
	tot = 0;
	now = n;
	for(i = 2;i<=temp;++i)
		if(now%i == 0)
	{
		a[++tot] = i;
		b[tot] = 0;
		while(now%i==0)
		{
			++b[tot];
			now/=i;
		}
	}
	if(now!=1)
	{
		a[++tot] = now;
		b[tot] = 1;
	}
}

int main()
{
	long long m = 5;
	long long temp;
	scanf("%d",&T);
	int ans;
	while(T--)
	{
		ans = 0;
		scanf("%lld%lld%lld",&l,&r,&k);
		for(int i = l;i<=r;++i)
		{
			factor(i);
			temp = 1;
			for(int j = 0;j<=tot;++j)
			{
				temp*= (b[j]*k+1)%998244353;
				temp%= 998244353;
			}
			ans+=temp;
			ans%=998244353;
		}
		printf("%d\n",ans);

	}

}
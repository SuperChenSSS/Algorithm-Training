#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
/*
	POJ 2689 Prime Distance
	给出一个区间【L,U】,找出区间内容，相邻的距离最近的两个素数
	和距离最远的两个素数
	1<=L<U<=2,147,483,647 区间长度不超过1e6
	就是要筛选出[L,U]之间的素数
*/
const int maxn = 100010;
int prime[maxn+1];
void getPrime()
{
	memset(prime,0,sizeof(prime));
	for(int i=2;i<=maxn;i++)
	{
		if(!prime[i])	prime[++prime[0]] = i;
		for(int j=1;j<=prime[0] && prime[j]<=maxn/i;j++)
		{
			prime[prime[j]+i] = 1;
			if(i%prime[j]==0)	break;
		}
	}
}
bool notprime[1000010];
int prime2[1000010];
void getPrime2(int L,int R)
{
	memset(notprime,false,sizeof(notprime));
	if(L<2)	L = 2;
	for(int i=1;i<=prime[0] && (long long)prime[i]*prime[i]<=R;i++)
	{
		int s = L/prime[i]+(L%prime[i]>0);
		if(s==1)	s = 2;
		for(int j=s;(long long)j*prime[i]<=R;j++)
			if((long long)j*prime[i]>=L)
				notprime[j*prime[i]-L] = true;
	}
	prime2[0] = 0;
	for(int i=0;i<=R-L;i++)
		if(!notprime[i])
			prime2[++prime2[0]] = i + L;
}
int main()
{
	getPrime();
	int L,U;
	while(cin>>L>>U)
	{
		getPrime2(L, U);
		if(prime2[0]<2)
			cout<<"There are no adjacent primes.\n";
		else
		{
			int x1 = 0,x2 = 1e8,y1 = 0,y2 = 0;
			for(int i=1;i<prime2[0];i++)
			{
				if(prime2[i+1]-prime2[i]<x2-x1)
				{
					x1 = prime2[i];
					x2 = prime2[i+1];
				}
				if(prime2[i+1]-prime2[i]>y2-y1)
				{
					y1 = prime2[i];
					y2 = prime2[i+1];
				}
			}
			cout<<x1<<","<<x2<<" are closest, "<<y1<<","<<y2<<" are most distant.\n";
		}
	}
	return 0;
}
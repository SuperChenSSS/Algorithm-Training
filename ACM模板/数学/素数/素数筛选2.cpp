#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
/*
	素数筛选，筛选出小于等于maxn的素数
	prime[0]存的是素数的个数
*/
const int maxn = 1e4;
int prime[maxn+1];
void getPrime()
{
	memset(prime,0,sizeof(prime));
	for(int i=2;i<=maxn;i++)
	{
		if(!prime[i])	prime[++prime[0]] = i;
		for(int j=1;j<=prime[0] && prime[j]<=maxn/i;j++)
		{
			prime[prime[j]*i] = 1;
			if(i%prime[j]==0)	break;
		}
	}
}
int main() {
	
	return 0;
}
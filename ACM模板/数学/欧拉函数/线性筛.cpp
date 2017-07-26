#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
//线性筛：同时得到欧拉函数和素数表
const int maxn = 1e7;
bool check[maxn+10];
int phi[maxn+10];
int prime[maxn+10];
int tot;//素数的个数
void phi_and_prime_table(int n)
{
	memset(check,false,sizeof(check));
	phi[1] = 1;
	tot = 0;
	for(int i=2;i<=n;i++)
	{
		if(!check[i])
		{
			prime[tot++] = i;
			phi[i] = i-1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>n)	break;
			check[i*prime[j]] = true;
			if(i % prime[j] == 0)
			{
				phi[i*prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i*prime[j]] = phi[i] * (prime[j]-1);
		}
	}
}
int main()
{
	
	return 0;
}
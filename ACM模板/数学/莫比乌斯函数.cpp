//通过线性筛选法求解莫比乌斯函数
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e6;
bool check[maxn+10];
int prime[maxn+10];
int mu[maxn+10];
void Moblus()
{
	memset(check,false,sizeof(check));
	mu[1] = 1;
	int tot = 0;
	for(int i=2;i<=maxn;i++)
	{
		if(!check[i])
		{
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>maxn)	break;
			check[i*prime[j]] = true;
			if(i%prime[j] == 0)
			{
				mu[i*prime[j]] = 0;
				break;
			}
			else
				mu[i*prime[j]] = -mu[i];
		}
	}
}
int main()
{
	
	return 0;
}
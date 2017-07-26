#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
/*
	素数筛选：判断小于maxn的数是不是素数，
	notprime是一张表，为false表示是素数，true表示不是素数
*/
const int maxn = 1000010;
bool notprime[maxn];//值为flase表示素数，值为true表示非素数
void init()
{
	memset(notprime,false,sizeof(notprime));
	notprime[0] = notprime[1] = true;
	for(int i=2;i<maxn;i++)
		if(!notprime[i])
		{
			if(i> maxn/i)	continue;//防止后面i*i溢出（或者i，j用long long）
			//直接从i*i开始就可以，小于i倍的已经筛选过了，注意是j+=i
			for(int j=i*i;j<maxn;j+=i)
				notprime[j] = true;
		}
}
int main() 
{
	
	return 0;
}
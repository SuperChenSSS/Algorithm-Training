#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
//所谓欧拉函数：对于一个正整数n，小于n且和n 互质的正整数（包括1 ）的个数，记做φ(n) 。
//通式：φ(x)=x*(1-1/p1)*(1-1/p2)*(1-1/p3)*(1-1/p4)…..(1-1/pn),
//其中p1, p2……pn为x的所有质因数，x是不为0的整数。φ(1)=1（唯一和1互质的数就是1本身）。
int euler[1000005];
void getEuler()
{
	memset(euler,0,sizeof(euler));
	euler[1] = 1;
	for(int i=2;i<=1000000;i++)
		if(!euler[i])
			for(int j=i;j<1000000;j+=i)
			{
				if(!euler[j])
					euler[j] = j;
				euler[j] = euler[j]/i*(i-1);
			}
}
int main()
{
	
	return 0;
}
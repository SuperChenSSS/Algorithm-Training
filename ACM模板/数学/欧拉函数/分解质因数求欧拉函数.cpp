#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
//分解质因数法求欧拉函数
int fatCnt,factor[100][100];
int getFactors(int n)
{
	int ret = n;
	for(int i=0;i<fatCnt;i++)
		ret = ret / factor[i][0] * (factor[i][0] - 1);
	return ret;
}
int main()
{
	
	return 0;
}
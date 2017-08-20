//RMQ用途：
//对于长度为n的数列A，回答若干询问RMQ（A,i,j）(i,j<=n)，
//返回数列A中下标在i，j之间的最小/大值。
/*一维
求最大值，数组下标从1开始
求最小值，或者最大最小值下标，或者数组从0开始对应修改即可
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50010;
int dp[MAXN][20];
int mm[MAXN];
//初始化RMQ,b数组下标从1开始，从0开始简单修改
void initRMQ(int n,int b[])
{
	mm[0] = -1;
	for(int i = 1; i <= n;i++)
	{
		mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
		dp[i][0] = b[i];
	}
for(int j = 1; j <= mm[n];j++)
	for(int i = 1;i + (1<<j) -1 <= n;i++)
		dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

//查询最大值
int rmq(int x,int y)
{
	int k = mm[y-x+1];
	return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
int main()
{
	
	return 0;
}
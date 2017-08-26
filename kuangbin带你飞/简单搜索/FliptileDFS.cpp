#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int g[17][17];         //保存初始状态　
int f[17][17];
int ans[17][17];
int mmin = 0x1f1ffff;

bool judge(int n,int m)//判断最后一行是否全为0
{
	for(int i=1;i<=m;i++)
	{
		int t = f[n][i]+f[n][i-1]+f[n][i+1]+f[n-1][i];
		if((g[n][i]+t)&1)
			return false;
	}
	return true;
}

void dfs(int n,int m,int k,int num)
{
	if(num > mmin)//剪枝
		return;
	if(k > n)
	{
		if(judge(n, m) && mmin>num)//判断是否符合条件
		{
			memcpy(ans, f, sizeof(f));
			mmin = num;
		}
		return;
	}
	int t = 0;
	for(int i=1;i<=m;i++)
	{
		if((g[k-1][i]+f[k-2][i]+f[k-1][i-1]+f[k-1][i+1]+f[k-1][i])&1)//上一行是否为1，即是否需要翻转
		{
			f[k][i] = 1;
			t++;
		}
		else
			f[k][i] = 0;
	}
	dfs(n, m, k+1, num+t);
}

//n,m行列数   k当前列  num第一行翻转的次数
void todfs(int n, int m, int k, int num)
{
	if(k > m)
	{
		dfs(n, m, 2, num); //对第一行每种情况进行搜索
		return;
	}
	f[1][k] = 0;      //不翻转
	todfs(n, m, k+1, num);
	f[1][k] = 1;      //翻转，num＋1
	todfs(n, m, k+1, num+1);
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)//下标从1开始，便于边界处理
			cin>>g[i][j];
	todfs(n, m, 1, 0);     //递归遍历第一行所有情况
	if(mmin == INF)
		cout<<"IMPOSSIBLE"<<endl;
	else
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	return 0;
}
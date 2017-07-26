#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
const int maxn = 1e3;
int n,W;
int w[maxn],v[maxn];
int dp[maxn+1][maxn+1];
using namespace std;

//从第i个物品开始挑选总重小于j的部分
int rec(int i,int j)
{
	if(dp[i][j]>=0)
		return dp[i][j];//已经计算过的话直接使用之前的结果
	int res;
	if(i == n){
		//已经没有剩余的物品了
		res = 0;
	} else if(j < w[i]){
		//无法挑选这个物品
		res = rec(i + 1, j);
	} else {
		//挑选和不挑选的两种情况都试一下
		res = max(rec(i+1,j),rec(i+1,j-w[i]) + v[i]);
	}
	return dp[i][j] = res;
}
int main() {
	freopen("bag.txt","r",stdin);
	while (cin>>n>>W) {
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			cin>>w[i]>>v[i];
		}
		cout<<rec(0,W)<<"\n";
	}
	return 0;
}
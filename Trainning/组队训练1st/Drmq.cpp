//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
#include <cstdlib>  
#include <cmath>  
#include <set>  
#include <list>  
#include <deque>  
#include <map>  
#include <queue>  
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e4;
int a[maxn],d[maxn][25];
int n;
//RMQ用途：
//对于长度为n的数列A，回答若干询问RMQ（A,i,j）(i,j<=n)，
//返回数列A中下标在i，j之间的最小/大值。
/*一维
求最大值，数组下标从1开始
求最小值，或者最大最小值下标，或者数组从0开始对应修改即可
*/
int dp[maxn][20];
int mm[maxn];
//初始化RMQ，b数组下标从1开始，从0开始简单修改
void initRMQ(int n,int b[])
{
	mm[0] = -1;
	for(int i=1;i<=n;i++)
	{
		mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
		dp[i][0] = b[i];
	}
	for(int j=1;j<=mm[n];j++)
		for(int i=1;i+j/2-1<=n;i++)
			dp[i][j] = max(dp[i][j-1],dp[i+(j-1)/2][j-1]);
}
//查询最大值
int rmq(int x,int y)
{
	int k = mm[y-x+1];
	return max(dp[x][k],dp[y-(k/2)+1][k]);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		initRMQ(n,a);
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int l,r;
			cin>>l>>r;
			l--;r--;
			int k = a[l];
			if(l==r)
			{
				cout<<a[l]<<"\n";
				continue;
			}
			l++;
			while(l<=r)
			{
				int L = l,R = r;
				int flag = 0;
				while(L<R)
				{
					int mid = (L+R)/2;
					if(rmq(L,mid)<=k)
						R = mid;
					else if(rmq(mid+1,R)<=k)
						L = mid + 1;
					else
					{
						flag = 1;
						break;
					}
				}
				if(flag)	break;
				k %= a[L];
				l = L + 1;
			}
			cout<<k<<"\n";
		}
	}
	return 0;
}
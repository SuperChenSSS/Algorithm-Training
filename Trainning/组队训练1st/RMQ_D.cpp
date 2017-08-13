#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100010;
int dp[MAXN][20];
int mm[MAXN];
int  k = 0;

void initRMQ(int n,int b[])
{
	mm[0] = -1;
	for(int i = 1; i <= n; i++)
	{
		mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
		dp[i][0] = b[i];
	}
	for(int j = 1; j <= mm[n]; j++)
		for(int i = 1; i + (1<<j) -1 <= n; i++)
			dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq(int x,int y)
{
	k = mm[y-x+1];
	return min(dp[x][k],dp[y-(1<<k)+1][k]);
}

int main()
{
	ios::sync_with_stdio(false) ;
	int T ,N , M, l , r ;
	int A[100010] ;
	cin >> T ;
	while(T --)
	{
		cin >> N;
		for(int i = 1 ; i <= N ; i ++)
		{
			cin >> A[i];
		}
		cin >> M ;
		while(M --)
		{
			cin >> l >> r ;
			int ans = A[l] ;
			initRMQ(N , A) ;
			for(int i = l+1 ; i <=r ; i++)
			{
				int index = rmq(l,r);
				if(index == 0)
				{
					continue ;
				}
				if(ans > index)
				{
					ans = ans % index ;
					A[k] = 1e9+1 ;
				}
				else
					break ;
			}
			cout << ans << endl;
		}
	}
	return 0 ;
}
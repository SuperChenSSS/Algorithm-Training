//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
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
const int maxn = 20;
const int mod = (1e9+7); 
int arr[maxn][maxn];
int f[maxn][maxn];
int ans[maxn][maxn];
int mmin = INF;
bool judge(int n,int m)//判断最后一行是否全为0
{
	for(int i=1;i<=m;i++)
	{
		int t = f[n][i] + f[n][i-1] + f[n][i+1] + f[n-1][i];
		if((arr[n][i]+t) & 1)
			return false;
	}
	return true;
}
void fun(int n,int m,int num)
{
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(num>mmin)
				return;
			if((arr[i-1][j]+f[i-2][j]+f[i-1][j-1]+f[i-1][j+1]+f[i-1][j])&1)//上一行是否为1，即是否需要翻转
			{
				f[i][j] = 1;
				++num;
			}
			else
				f[i][j] = 0;
		}
		if(judge(n, m) && mmin>num)//判断是否符合条件
		{
			memcpy(ans,f,sizeof(f));
			mmin = num;
		}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>arr[i][j];
		for(int i=0;i<1<<(m+1);i++)
		{
			int num = 0;
			for(int j=1;j<=m;j++)
			{
				f[1][j] = i >>(m-j+1) & 1;
				num += f[1][j];
			}
			fun(n,m,num);
		}
		if(mmin==INF)
			cout<<"IMPOSSIBLE\n";
		else
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					if(j!=m)
						cout<<ans[i][j]<<" ";
					else
						cout<<ans[i][j];
				cout<<"\n";
			}
	}
	return 0;
}
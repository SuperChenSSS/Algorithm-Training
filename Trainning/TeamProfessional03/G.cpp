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
const int maxn = 1e3;
const int mod = (1e9+7); 
const int MAXN = 510;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
	for(int v = 0; v < vN;v++)
	if(g[u][v] && !used[v])
	{
		used[v] = true;
		if(linker[v] == -1 || dfs(linker[v]))
		{
			linker[v] = u;
			return true;
		}
	}
	return false;
}

int hungary()
{
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int u = 0;u < uN;u++)
	{
		memset(used,false,sizeof(used));
		if(dfs(u))
			res++;
	}
	return res;
}
char arr[maxn];
char compare[maxn][maxn];
int main()
{
	//freopen("1.txt","r",stdin);
	int n;
	while(cin>>arr)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<6;j++)
				cin>>compare[i][j];
		uN = strlen(arr);
		vN = 6 * n;
		for(int i=0;i<strlen(arr);i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<6;k++)
				{
					if(arr[i]==compare[j][k])
					{
						g[i][j] = 1;
						break;
					}
				}
		int res = hungary();
		//cout<<res<<strlen(arr)<<"\n";
		if(res==strlen(arr))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
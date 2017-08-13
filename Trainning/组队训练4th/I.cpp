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
const int maxm = 1e6;
const int mod = (1e9+7); 
int n,m;
bool g[maxn][maxn],visit[maxm],flag;
int w[maxm];
bool dfs(int i,int pre)
{
	visit[i] = true;
	for(int j=1;j<=n;j++)
		if(g[i][j])
		{
			if(!visit[j])
				return dfs(j,i);
			else if(j!=pre)
				return false;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m && n||m)
	{
		memset(w,0,sizeof(w));
		memset(g,0,sizeof(g));
		for(int i=0;i<m;i++)
		{
			int j,k;
			cin>>j>>k>>w[i];
			g[j][k] = g[k][j] = true;
		}
		memset(visit,0,sizeof(visit));
		flag = dfs(1,0);
		if(flag)
		{
			sort(w,w+m);
			cout<<w[0]<<"\n";
		}
		else
			cout<<"-1\n";
	}
	return 0;
}
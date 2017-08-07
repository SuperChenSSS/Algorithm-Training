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
const int INF = 0x3f3f3f3f;  
const int maxn = 1e6;
const int mod = (1e9+7); 
int g[1005][1005];
int vis[1005][1005];
int d[4][2] = {1,0,0,1,-1,0,0,-1};
int n,m;
int cal(int x1,int y1,int x2,int y2)
{
	return abs(g[x1][y1] - g[x2][y2]);
}

struct lowercost
{
	int x,y;
	int cost;
	bool operator <(const lowercost &temp)const
	{
		return cost>temp.cost;
	}	
};

void init()
{
	memset(vis,0,sizeof(vis));
}

int prim()
{
	priority_queue<lowercost>q;
	lowercost t1,t2;
	int sum = 0,i,cnt;
	t1.x = t1.y = t1.cost = 0;
	q.push(t1);
	cnt = 0;
	while(!q.empty())
	{
		t1 = q.top();
		q.pop();
		if(vis[t1.x][t1.y])
			continue;
		vis[t1.x][t1.y] = 1;
		sum += t1.cost;
		for(i=0;i<4;i++)
		{
			t2.x = t1.x + d[i][0];
			t2.y = t1.y + d[i][1];
			t2.cost = cal(t1.x,t1.y,t2.x,t2.y);
			if(t2.x>=0 && t2.x<m && t2.y>=0 && t2.y<n && !vis[t2.x][t2.y])
				q.push(t2);
		}
	}
	return sum;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		init();
		cin>>m>>n;
		for(int j=0;j<m;j++)
			for(int k=0;k<n;k++)
				cin>>g[j][k];
		int ans = prim();
		printf("Case #%d:\n",i);
		printf("%d\n",ans);
	}
	return 0;
}
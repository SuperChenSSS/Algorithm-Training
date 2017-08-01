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
const int maxn = 1e6;
int n,vis[maxn],d[maxn];
set<int> S[maxn];
vector<int> g[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		d[a]++;
		d[b]++;
	}
	//bfs
	queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==1)
		{
			Q.push(i);
			S[i].insert(0);
		}
	}
	while(!Q.empty())
	{
		int now = Q.front();
		vis[now] = 1;
		Q.pop();
		for(int i=0;i<g[now].size();i++)
		{
			int v = g[now][i];
			if(vis[v])	continue;
			S[v].insert((*S[now].begin())+1);
			d[v]--;
			if(d[v]==1 && S[v].size()==1)
				Q.push(v);
		}
	}
	int ans = 0,num2 = 0;
	for(int i=1;i<=n;i++)
	{
		if(S[i].size()==0)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(S[i].size()>2)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(S[i].size()==1)
			ans = max(ans, *S[i].begin());
		if(S[i].size()==2)
		{
			ans = max(ans,*S[i].begin()+*S[i].rbegin());
			num2++;
		}
	}
	if(num2>1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	while(ans%2==0)
		ans /= 2;
	cout<<ans<<endl;
	return 0;
}
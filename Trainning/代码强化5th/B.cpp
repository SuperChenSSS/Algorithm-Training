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
struct Node
{
	int to;
	int cap;
	int rev;
};
vector<Node> v[maxn];
bool used[maxn];
void add_Node(int from,int to,int cap)//重边情况不影响
{
	v[from].push_back((Node){to,cap,v[to].size()});
	v[to].push_back(Node);
}
int dfs(int s,int t,int f)
{
	if(s==t)
		return f;
	used[s] = true;
	for(int i=0;i<v[s].size();i++)
	{
		Node &tmp = v[s][i];//注意
		if(used[tmp.to]==false && tmp.cap>0)
		{
			int d = dfs(tmp.to,t,min(f,tmp.cap));
			if(d>0)
			{
				tmp.cap -= d;
				v[tmp.to][tmp.rev].cap += d;
				return d;
			}
		}
	}
	return 0;	
}
int max_flow(int s,int t)
{
	int flow = 0;
	for(;;)
	{
		memset(used,false,sizeof(used));
		int f = dfs(s,t,INF);
		if(f==0)
			return flow;
		flow += f;
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
		}
		cout<<max_flow(1, m)<<"\n";
	}
	return 0;
}
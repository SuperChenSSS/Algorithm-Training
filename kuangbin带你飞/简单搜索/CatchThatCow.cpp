//TDteam01
/*
具体思路：
设图G的初态是所有顶点均未访问，在G 中任选一顶点i作为初始点，则广度优先搜索的基本思想是：
（1）从图中的某个顶点V出发，访问之；并将其访问标志置为已被访问，即visited[i]=1；

（2）依次访问顶点V的各个未被访问过的邻接 点，将V的全部邻接点都访问到；

（3）分别从这些邻接点出发，依次访问它们的未被访问过的邻接点，
并使“先被访问的顶点的邻接点”先于“后被访问的顶点的邻接点”被访问，
直到图中所有已被访问过的顶 点的邻接点都被访问到。
依此类推，直到图中所有顶点都被访问完为止 。
广度优先搜索在搜索访问一层时，需要记住已被访问的顶点，以便在访问下层顶点时，
从已被访问的顶点出发搜索访问其邻接点。所以在广度优先搜索中需要设置一个队列Queue，使已被访问的顶点顺序由队尾进入队列。
在搜索访问下层顶点时，先从队首取出一个已被访问的上层顶点，再从该顶点出发搜索访问它的各个邻接点。
*/
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
const int maxn = 1e6;
const int mod = (1e9+7); 
int vis[maxn];
struct node
{
	int x;
	int step;
	node(int mx=0,int mstep=0)
	{
		x = mx;
		step = mstep;
	}
};
queue<node> q;
int bfs(int n,int k)
{
	while(!q.empty())
		q.pop();
	struct node head(n,0);
	struct node next;
	q.push(head);
	vis[head.x] = 1;
	while(!q.empty())
	{
		head = q.front();
		q.pop();
		for(int i=0;i<3;i++)
		{
			if(i==0)
				next.x = head.x - 1;
			else if(i==1)
				next.x = head.x + 1;
			else
				next.x = head.x * 2;
			if(next.x<0||next.x>maxn)
				continue;
			if(!vis[next.x])
			{
				vis[next.x] = 1;
				next.step = head.step + 1;
				q.push(next);
			}
			if(next.x == k)
				return next.step;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k)
	{
		memset(vis,0,sizeof(vis));
		if(n>=k)
			cout<<n-k<<"\n";
		else
		{
			int res = bfs(n,k);
			cout<<res<<"\n";
		}
	}
	return 0;
}
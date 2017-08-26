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
const int maxn = 1e6;
const int mod = (1e9+7); 
bool vis[maxn];//标记数组
int step[maxn];//记录到了每一位置所走的步数
queue<int> q;
int bfs(int n,int k)
{
	int head,next;
	q.push(n);//开始在n位置，n入队
	step[n] = 0;
	vis[n] = true;//标记已经访问
	while(!q.empty())//队列非空
	{
		head = q.front();
		q.pop();
		for(int i=0;i<3;i++)//记录三种走法
		{
			if(i==0)
				next = head - 1;
			else if(i==1)
				next = head + 1;
			else
				next = head * 2;
			if(next<0 || next >=maxn)
				continue;//排除出界情况
			if(!vis[next])//如果next位置未被访问
			{
				q.push(next);//入队
				step[next] = step[head] + 1;//步数+1
				vis[next] = true;//标记已访问
			}
			if(next==k)
				return step[next];//当遍历到结果，返回步数
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k)
	{
		memset(step,0,sizeof(step));
		memset(vis,false,sizeof(vis));
		while(!q.empty())
			q.pop();//注意调用前要先清空
		if(n>=k)
			cout<<n-k<<"\n";
		else
			cout<<bfs(n,k)<<"\n";
	}
	return 0;
}
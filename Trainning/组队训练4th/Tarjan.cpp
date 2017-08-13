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
using std::cin;
using std::cout;  
using std::min;
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
struct node
{
	int v,next;
}edge[1001];
int DFN[1001],LOW[1001];
int stack[1001],heads[1001],visit[1001],cnt,tot,ind;
void add(int x,int y)
{
	edge[++cnt].next = heads[x];
	edge[cnt].v = y;
	heads[x] = cnt;
	return;
}
void tarjan(int x)//代表几个点在处理，递归的是点
{
	DFN[x] = LOW[x] = ++tot;//新进点的初始化
	stack[++ind] = x;//进站
	visit[x] = 1;//表示在栈里
	for(int i=heads[x];i!=-1;i=edge[i].next)
	{
		if(!DFN[edge[i].v])//如果没访问过
		{
			tarjan(edge[i].v);//往下进行延伸，开始递归
			LOW[x] = min(LOW[x],LOW[edge[i].v]);//递归出来，比较谁是谁的儿子/父亲，就是树的对应关系，涉及到强连通分量子树最小根的事情
		}
		else if(visit[edge[i].v])//如果访问过，并且还在栈里
			LOW[x] = min(LOW[x],DFN[edge[i].v]);//比较谁是谁的儿子/父亲
	}
	if(LOW[x]==DFN[x])//发现是整个强连通分量子树的最小根
	{
		do{
			printf("%d ",stack[ind]);
			visit[stack[ind]] = 0;
			ind--;
		}while(x!=stack[ind+1]);//出栈，并且输出
		printf("\n");
	}
	return ;
}
int main()
{
	memset(heads,-1,sizeof(heads));
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!DFN[i])
			tarjan(i);//当这个点没有访问过，就从此点开始。防止图没走完
	return 0;
}
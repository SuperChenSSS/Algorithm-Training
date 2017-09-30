#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
//并查集模板
int pre[1050];
bool t[1050];//t用于标记独立块的根节点
int Find(int x)//查找我(x)的掌门
{
	int r = x;//委托r去找掌门
	while(r!=pre[r])//如果r的上级不是r自己(也就是说找到的大侠他不是掌门)
		r = pre[r];//r就接着找他的掌门，直到掌门为止
	int i = x,j;
	while(pre[i]!=r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;//掌门驾到
}
void mix(int x,int y) //我想让虚竹和周芷若做朋友
{
	int fx = Find(x),fy = Find(y);//虚竹的老大是玄慈，芷若MM的老大是灭绝
	if(fx!=fy)  //玄慈和灭绝显然不是同一个人
		pre[fy] = fx; //方丈只好委委屈屈地当了师太的手下啦
}
int main()
{
	//freopen("road.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m && n!=0)
	{
		int a,b,ans=0;
		for(int i=1;i<=n;i++)//初始化
			pre[i] = i;
		for(int i=1;i<=m;i++)//吸收并整理数据
		{
			cin>>a>>b;
			mix(a,b);
		}
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++)
			t[Find(i)] = 1;
		for(int i=1;i<=n;i++)
			if(t[i])
				ans++;
		cout<<ans-1<<endl;
	}
	return 0;
}
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
//那么怎么求已线段与一直线相交呢？？
//还记得右手法则吗？
//假如 AB,X,BC与AB,X,BD的符号不一致是什么情况呢？？说明从AB到BC与从AB到BD的方向不一致（顺时针与逆时针）
struct Point
{
	double x,y;
	void in()
	{
		cin>>x>>y;
	}
}a,b,c,d;
int sreach(Point a,Point b,Point c,Point d)  
{  
	double p[4];  
	p[0]=(b.x-a.x)*(b.y-c.y)-(b.y-a.y)*(b.x-c.x);  
	p[1]=(b.x-a.x)*(b.y-d.y)-(b.y-a.y)*(b.x-d.x);  
	p[2]=(d.x-c.x)*(d.y-a.y)-(d.y-c.y)*(d.x-a.x);  
	p[3]=(d.x-c.x)*(d.y-b.y)-(d.y-c.y)*(d.x-b.x);  
	if ((p[0]*p[1]<=0)&&(p[2]*p[3]<=0))  
		return true;  
	return false;  
}  
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		a.in();b.in();c.in();d.in();
		int flag = sreach(a,b,c,d);
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
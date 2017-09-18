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
struct Point
{
	double x,y;
	Point(){}
	Point(ll _x,ll _y)
	{
		x = _x; y = _y;
	}
	Point operator -(const Point &b)const
	{
		return Point(x - b.x, y - b.y);
	}
	double operator ^(const Point &b)const
	{
		return x*b.y - y*b.x;
	}
	double operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
}; 
//过三点求圆心坐标
Point waixin(Point a,Point b,Point c)
{
	double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;
	double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;
	double d = a1*b2 - a2*b1;
	return Point(a.x + (c1*b2 - c2*b1)/d, a.y + (a1*c2 -a2*c1)/d);
}
//两点间距离
double dist(Point a,Point b)
{
	return (a-b)*(a-b);
}
int main()
{
	freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		Point a,b,c,target,circle;
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>target.x>>target.y;
		circle = waixin(a, b, c);
		double r = 0,len = 0;
		r = dist(circle,a);
		len = dist(circle,target);
		if(len>r)
			cout<<"Accepted\n";
		else
			cout<<"Rejected\n";
	}
	return 0;
}
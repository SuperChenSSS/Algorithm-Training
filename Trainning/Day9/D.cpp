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
int sgn(double x)
{
	if(fabs(x)<eps)	return 0;
	if(x<0)	return -1;
	else	return 1;
}
struct Point{
	double x,y;
	Point(){}
	Point (double _x,double _y)
	{
		x = _x;y = _y; 
	}
	Point operator -(const Point &b)const
	{
		return Point(x-b.x,y-b.y);
	}
	//叉积
	double operator ^(const Point &b)const
	{
		return x*b.y-y*b.x;
	}
	//点积
	double operator *(const Point &b)const
	{
		return x*b.x-y*b.y;
	}
}poly[maxn];
struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s=  _s;e = _e;
	}
};
//判断点在线段上
bool OnSeg(Point P,Line L)
{
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
//判断两条线相交
bool inter(Line l1,Line l2)
{
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

//判断凸多边形
bool isconvex(Point poly[],int n)
{
	bool s[3];
	memset(s,false,sizeof(s));
	for(int i=0;i<n;i++)
	{
		s[sgn( (poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]) )+1] = true;
		if(s[0] && s[2])
			return false;
	}
	return true;
}

int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;i++)
			cin>>poly[i].x>>poly[i].y;
		if(isconvex(poly, n))
			cout<<"convex\n";
		else
			cout<<"concave\n";
	}
	return 0;
}
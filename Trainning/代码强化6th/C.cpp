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
const double eps = 1e-8;  
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
}ba[maxn],jian[maxn];
struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;e = _e;
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
//判断点在任意多边形内
int inPoly(Point p,Point poly[],int n)
{
	int cnt;
	Line ray,side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -100000000000.0;//-INF,注意取值防止越界
	for(int i=0;i<n;i++)
	{
		side.s = poly[i];
		side.e = poly[(i+1)%n];
		if(OnSeg(p,side))
			return 0;
		//如果平行轴则不考虑
		if(sgn(side.s.y-side.e.y)==0)
			continue;
		if(OnSeg(side.s,ray)){
			if(sgn(side.s.y-side.e.y)>0)	cnt++;
		}
		else if(OnSeg(side.e,ray)){
			if(sgn(side.e.y-side.s.y)>0)	cnt++;
		}
		else if(inter(ray,side))	cnt++;
	}
	if(cnt % 2 == 1)	return 1;
	else	return -1;
}
int main()
{
	int n,m;
	while(cin>>n)
	{
		for(int i=0;i<n;i++){
			cin>>ba[i].x>>ba[i].y;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>jian[i].x>>jian[i].y;
			if(inPoly(jian[i],ba,n)>=0)
				cout<<"Yes"<<"\n";
			else
				cout<<"No"<<"\n";
		}
	}
	return 0;
}
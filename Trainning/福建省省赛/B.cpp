#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x)
{
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	else return 1;
}

struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x = _x; y = _y;
	}
	Point operator -(const Point &b)
	{
		return Point(x-b.x,y-b.y);
	}
	double operator ^(const Point&b)
	{
		return (x*b.y) - (y*b.x);
	}
	double operator *(const Point &b)
	{
		return x*b.x+y*b.y;
	}
};

struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;e = _e;
	}
};

bool inter(Line l1,Line l2)
{
	return
	max(l1.s.x,l1.e.x)>=min(l2.s.x,l2.e.x)&&
	max(l2.s.x,l2.e.x)>=min(l1.s.x,l1.e.x)&&
	max(l1.s.y,l1.e.y)>=min(l2.s.y,l2.e.y)&&
	max(l2.s.y,l2.e.y)>=min(l1.s.y,l1.e.y)&&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e))<=0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e))<=0;
}

bool OnSeg(Point P,Line L)
{
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x-L.s.x)*(P.x-L.e.x))<=0 &&
	sgn((P.y-L.s.y)*(P.y-L.e.y))<= 0;
}

int inPoly(Point p,Point Poly[],int n)
{
	int cnt;
	Line ray,side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -1000000000.0;
	for(int i = 0;i<n;++i)
	{
		side.s = Poly[i];
		side.e = Poly[(i+1)%n];
		if(OnSeg(p,side)) return 0;
		if(sgn(side.s.y-side.e.y)==0)
			continue;
		if(OnSeg(side.s,ray))
		{
			if(sgn(side.s.y-side.e.y)>0)cnt++;
		}
		else if(OnSeg(side.e,ray))
		{
			if(sgn(side.e.y-side.s.y)>0)cnt++;
		}
		else if(inter(ray,side))
			cnt++;
	}
	if(cnt%2 == 1)return 1;
	else return -1;
}

int main()
{
	int tf[11];
	int ainb[4],bina[4];
	int m,temp;
	int T,i = 0;
	cin>>T;
		int x,y;
		Point Poly1[3],Poly2[3];
		while(T--)
		{
			for(m = 0;m<3;++m)
			{
				cin>>x>>y;
				Poly1[m] = Point(x,y);
			}
			for(m = 0;m<3;++m)
			{
				cin>>x>>y;
				Poly2[m] = Point(x,y);
			}
			for(m = 0;m<3;++m)
			{
				ainb[m] = inPoly(Poly1[m],Poly2,3);
				if(ainb[m]==0)
				{
					tf[i] = 0;
				}
			}
			if(ainb[0]==ainb[1]&&ainb[1]==ainb[2]&&ainb[0] == -1)
			{
				for(int p = 0;p<3;++p)
				{
				bina[p] = inPoly(Poly2[p],Poly1,3);
				}
				if(bina[0]==bina[1]&&bina[1]==bina[2]&&bina[0] == -1)
				{
					tf[i] = -1;
				}
				else if(bina[0]==bina[1]&&bina[1]==bina[2]&&bina[0] == 1)
				{
					tf[i] = 1;
				}
				else
					tf[i] = 0;
			}
			else
				tf[i] = 0;
			++i;
		}
		for(m = 0;m<i;++m)
		{
			switch(tf[m])
			{
				case -1:printf("disjoint\n");break;
				case 0:printf("intersect\n");break;
				case 1:printf("contain\n");break;
			}
		}
	return 0;
}
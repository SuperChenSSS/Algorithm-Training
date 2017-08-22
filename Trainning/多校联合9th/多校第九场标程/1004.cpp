#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>

#define MAXN 5000
#define eps 1e-9

struct point
{
	double x,y;
	point(double a = 0,double b = 0)
	{
		x = a; y = b;
	}
	friend point operator + (point a,point b)
	{
		return point(a.x+b.x,a.y+b.y);
	}
	friend point operator - (point a,point b)
	{
		return point(a.x-b.x,a.y-b.y);
	}
	friend double operator ^ (point a,point b)
	{
		return a.x*b.y-a.y*b.x;
	}
	friend double operator * (point a,point b)
	{
		return a.x*b.x+a.y*b.y;
	}
	friend point operator * (point a,double b)
	{
		return point(a.x*b,a.y*b);
	}
	friend point operator * (double a,point b)
	{
		return point(a*b.x,a*b.y);
	}

};

struct line
{
	point s,e;
	line(point a = point(0,0),point b = point(0,0))
	{
		s = a; e = b;
	}
};

point p[MAXN+5];
double c[MAXN+5];
int n;
point s[2];

int sgn(double x)
{
	if (x>eps) return 1;
	if (x<-eps) return -1;
	return 0;
}

point Get_Intersect(line a,line b)
{						   
    double u=(a.e-a.s)^(b.s-a.s);
    double v=(a.s-a.e)^(b.e-a.e);
    point p;
    p.x=(b.s.x*v+b.e.x*u)/(v+u);
    p.y=(b.s.y*v+b.e.y*u)/(v+u);
    return p;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&c[i]);
	p[n] = p[0];
	s[0] = point(0,0);
	scanf("%lf%lf",&s[1].x,&s[1].y);
	
	double now = 1.0;
	int ans = 0;
	bool flag = 1;
	point temp;
	point temp2;
	line l1,l2,l3,l4;
	while (now > 1e-4)
	{
		ans++;
		for (int i=0;i<n;i++)
		{
			if (!sgn((p[i]-s[0])^s[1]))
			{
				now = 0;
				flag = 0;
				break;
			}
		}
		if (!flag) break;
		for (int i=0;i<n;i++)
		{
			if (sgn((p[i]-s[0])^s[1]) > 0 && sgn(s[1]^(p[i+1]-s[0]))>0)
			{
				l1 = line(p[i+1],p[i]);
				l2 = line(s[0],s[1]+s[0]);
				temp = Get_Intersect(l1,l2);
				
				l3 = line(temp,point(p[i+1].y-p[i].y,p[i].x-p[i+1].x)+temp);
				l4 = line(s[0],point(p[i].x-p[i+1].x,p[i].y-p[i+1].y)+s[0]);
				
				temp2 = Get_Intersect(l3,l4);
				temp2 = 2*temp2-s[0];
				s[0] = temp;
				s[1] = temp2-s[0];
				now *= c[i];
				break;
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}

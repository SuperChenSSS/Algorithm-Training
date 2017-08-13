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
const double eps = 1e-9;
int N,T;

int cmp(double x)
{
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	return -1;
}

inline double sqr(double x)
{
	return x*x;
}

struct pt
{
	double x,y;
	pt(){}
	pt(double a,double b):x(a),y(b){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	friend pt operator+(const pt &a,const pt &b)
	{
		return pt(a.x + b.x, a.y+ b.y);
	}
	friend pt operator-(const pt &a,const pt &b)
	{
		return pt(a.x- b.x,a.y - b.y);
	}
	friend bool operator== (const pt &a,const pt &b)
	{
		return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
	}
	friend pt operator*(const double &a,const pt &b)
	{
		return pt(a*b.x,a*b.y);
	}
	friend pt operator/(const pt &a,const double &b)
	{
		return pt(a.x/b,a.y/b);
	}
	double norm()
	{
		return sqrt(sqr(x)+sqr(y));
	}
}a1,a2,ret[10],o(0.0000000000,0.0000000000);


double dist(const pt &a,const pt &b)
{
	return (a-b).norm();
}

void circle_line(pt a,pt b,pt o,double r,pt ret[],int &num)
{
	double x0 = o.x,y0 = o.y;
	double x1 = a.x,y1 = a.y;
	double x2 = b.x,y2 = b.y;
	double dx = x2- x1,dy = y2 - y1;
	double A = dx*dx + dy*dy;
	double B = 2*dx*(x1-x0) + 2*dy*(y1-y0);
	double C = sqr(x1-x0) + sqr(y1-y0) - sqr(r);
	double delta = B*B - 4*A*C;
	num = 0;
	if (cmp(delta)>=0)
	{
		double t1 = (-B - sqrt(delta)) / (2*A);
		double t2 = (-B - sqrt(delta)) / (2*A);
		//if(cmp(t1 - 1)<= 0 && cmp(t1)>=0)
		ret[num++] = pt(x1+t1*dx,y1+t1*dy);
		//if(cmp(t2 - 1)<= 0 && cmp(t2)>=0)
		ret[num++] = pt(x1+t2*dx,y1+t2*dy);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int num;
	double r,dis,dis1,dis2;
	pt temppt,temppt2,sp;
	//ret = new pt[10];
	freopen("1002.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf",&r);
		a1.input();
		a2.input();
		sp.x = (a1.x+a2.x)/2.0;
		sp.y = (a1.y+a2.y)/2.0;
		printf("Pointsp: %lf %lf\n",sp.x,sp.y);
		circle_line(a1,a2,o,r,ret,num);
		temppt = ret[0];
		printf("Point1: %lf %lf\n",temppt.x,temppt.y);
		circle_line(a2,a1,o,r,ret,num);
		printf("Point1: %lf %lf\n",ret[0].x,ret[0].y);
		dis = dist(temppt,ret[0]);
		printf("Condition 1:  %.7lf\n",dis);
		circle_line(sp,o,o,r,ret,num);
		dis1 = 2*dist(a2,ret[0]);
		printf("Pointsp1: %lf %lf\n",ret[0].x,ret[0].y);
		circle_line(o,sp,o,r,ret,num);
		dis2 = 2.0*dist(a1,ret[0]);
		printf("Pointsp2: %lf %lf\n",ret[0].x,ret[0].y);
		printf("Condition 2:  %.7lf\n",dis1);
		printf("Condition 2:  %.7lf\n",dis2);
		dis1 = min(dis1,dis2);
		circle_line(o,a1,o,r,ret,num);
		dis2 = dist(a1,ret[0])+dist(a2,ret[0]);
		dis1 = min(dis1,dis2);
		dis = min(dis1,dis);
		printf("The ans is:%.7lf\n",dis);
		printf("\n");
		//printf("%.7lf\n",dis);
	}
}
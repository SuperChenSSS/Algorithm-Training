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
int sgn(double x)
{
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
typedef struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{x = _x;y = _y;}	
}Point;
bool equals(Point a,Point b)
{
	if(a.x==b.x&&a.y==b.y)
		return true;
	else
		return false;
}
Point point[maxn];
double xielv(Point a,Point b)
{	
	if(b.x==a.x)
		return -1;
	else	
		return (b.y-a.y)/(b.x-a.x);	
}
typedef struct line
{
	Point s,e;
	line(Point _s,Point _e)
	{
		s = _s;e = _e;
	}
}line;
bool isOneLine(line a,line b)
{
	if(a.s.x+a.s.y+a.e.x+a.e.y==b.s.x+b.s.y+b.e.x+b.e.y)
		return true;
	else
		return false;
}
bool isParallel(line a,line b)
{
	if(xielv(a.s,a.e)==xielv(b.s,b.e)&&(!equals(a.s, b.s)&&!equals(a.e,b.e)&&!isOneLine(a,b)))
		return true;
	else
		return false;
}
int main()
{
	//freopen("9.1_2.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n;bool flag;
	while(cin>>n)
	{
		flag = false;
		for(int i=0;i<n;i++)
		{
			point[i].x = i;
			cin>>point[i].y;
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				line line1(point[i],point[j]);
				line line2(point[i-1],point[j-1]);
				if(isParallel(line1, line2))
					flag = true;
			}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
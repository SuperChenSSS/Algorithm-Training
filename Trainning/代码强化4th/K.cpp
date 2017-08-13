#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MOD = 10007;
int INV[MOD];
int n,r;

struct Point{
	int x,y;
	Point(int _x=0,int _y=0)
	{x = _x;y = _y;}
	Point operator -(const Point &b)const
	{return Point(x-b.x,y-b.y);}
	int operator ^(const Point &b)const
	{return x*b.y - y*b.x;}
	void input()
	{cin>>x>>y;}	
};
struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;
		e = _e;
	}	
};
bool onSeg(Point P,Line L)
{
	return
	((L.s-P)^(L.e-P)) == 0 &&
	(P.x-L.s.x)*(P.x-L.e.x) <= 0 &&
	(P.y-L.s.y)*(P.y-L.e.y) <= 0;
}
int sqdis(Point a,Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
//求ax=1(mod m)的x值，就是逆元(0<a<m)
long long inv(long long a,long long m)
{
	if(a == 1)
		return 1;
	return inv(m%a,m)*(m-m/a)%m;
}
struct Matrix
{
	int mat[330][330];
	void init()
	{
		memset(mat,0,sizeof(mat));
	}
	int det(int n)//求行列式的值模上MOD，需要使用逆元
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				mat[i][j] = (mat[i][j]%MOD+MOD)%MOD;
		int res = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
				if(mat[j][i]!=0)
				{
					for(int k=i;k<n;k++)
						swap(mat[i][k],mat[j][k]);
					if(i!=j)
						res = (-res+MOD)%MOD;
					break;
				}
			if(mat[i][i]==0)
			{
				res = -1;//不存在（也就是行列值为0）
				break;
			}
			for(int j=i+1;j<n;j++)
			{
				//int mut = (mat[j][i]*INV(mat[i][i]))%MOD;//打表逆元
				int mut = (mat[j][i]*inv(mat[i][i],MOD)) % MOD;
				for(int k=i;k<n;k++)
					mat[j][k] = (mat[j][k] - (mat[i][k]*mut)%MOD+MOD)%MOD;
			}
			res = (res * mat[i][i]) % MOD;
		}
		return res;
	}	
};
Point p[330];
bool check(int k1,int k2)//判断两点的距离小于等于R，而且中间没有点阻隔
{
	if(sqdis(p[k1], p[k2])>r*r)
		return false;
	for(int i=0;i<n;i++)
		if(i!=k1 && i!=k2)
			if(onSeg(p[i],Line(p[k1],p[k2])))
					return false;
	return true;	
}
int g[330][330];
int main()
{
	//预处理逆元
	for(int i=1;i<MOD;i++)
		INV[i] = inv(i,MOD);
	int t;
	cin>>t;
	while(t--)
	{		cin>>n>>r;
		for(int i=0;i<n;i++)
			p[i].input();
		memset(g,0,sizeof(g));
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(check(i,j))
					g[i][j] = g[j][i] = 1;
		Matrix ret;
		ret.init();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j && g[i][j])
				{
					ret.mat[i][j] = -1;
					ret.mat[i][i]++;
				}
		cout<<ret.det(n-1)<<"\n";
	}
	return 0;
}
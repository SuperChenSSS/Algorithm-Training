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
const int maxn = 100;
//莫队算法
struct note
{
	int x,y,x1,y1,z,wz;
}cz[50005];
bool cmp(note x,note y)
{
	return (x.x1<y.x1||(x.x1==y.x1 && x.y1<y.y1)
			||(x.x1==y.x1&&x.y1==y.y1&&x.z<y.z));
}
int n,m,a[50005],b[1000001],cg[50005][3],s[50005],size;
void up(int q,int k)
{
	for(int i=cz[q].z+1;i<=cz[k].z;i++)
	{
		if(k>1 && cg[i][0]>=cz[q].x && cg[i][0]<=cz[q].y)
		{
			if(b[cg[i][1]]==0)	s[cz[k].wz]++;
			b[cg[i][1]]++;
		}
		cg[i][2] = a[cg[i][0]];
		a[cg[i][0]] = cg[i][1];
		if(k>1 && cg[i][0]>=cz[q].x && cg[i][0]<=cz[q].y)
		{
			b[cg[i][2]]--;
			if(b[cg[i][2]]==0)	s[cz[k].wz]--;
		}
	}
}
void down(int q,int k)
{
	for(int i=cz[q].z;i<=cz[k].z+1;i++)
	{
		if(k>1 && cg[i][0]>=cz[q].x && cg[i][0]<=cz[q].y)
		{
			if(b[cg[i][2]]==0)
				s[cz[k].wz]++;
			b[cg[i][2]]++;
		}
		a[cg[i][0]] = cg[i][2];
		if(k>1 && cg[i][0]>=cz[q].x && cg[i][0]<=cz[q].y)
		{
			b[cg[i][1]]--;
			if(b[cg[i][1]]==0)
				s[cz[k].wz]--;
		}
		cg[i][2] = 0;
	}
}
void make(int k,int l,int r,int v)
{
	for(int i=l;i<=r;i++)
	{
		if(b[a[i]]==0 && v==1)
			s[cz[k].wz]++;
		b[a[i]] += v;
		if(b[a[i]]==0 && v==-1)
			s[cz[k].wz]--;
	}
}
int main()
{
	cin>>n>>m;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	scanf("\n");
	size = (int)pow(n,2.0/3);
	int time = 0,num = 0;
	for(int i=1;i<=m;i++)
	{
		char ch;
		int x,y;
		cin>>ch>>x>>y;
		scanf("\n");
		x++;
		if(ch=='Q')
		{
			cz[++num].x = x;
			cz[num].y = y;
			cz[num].x1 = (x-1)/size+1;
			cz[num].y1 = (y-1)/size+1;
			cz[num].z = time;
			cz[num].wz = num;
		}
		else
		{
			cg[++time][0] = x;
			cg[time][1] = y;
		}
	}
	sort(cz+1,cz+num+1,cmp);
	cz[0].z = 0;
	up(0,1);
	for(int i=cz[1].x;i<=cz[1].y;i++)
	{
		if(b[a[i]]==0)
			s[cz[1].wz]++;
		b[a[i]]++;
	}
	for(int i=2;i<=num;i++)
	{
		s[cz[i].wz] = s[cz[i-1].wz];
		if(cz[i].z<cz[i-1].z)
			down(i-1,i);
		else up(i-1,i);
		int x = cz[i-1].x,x1 = cz[i].x,y = cz[i-1].y,y1 = cz[i].y;
		if(x<x1)
			make(i,x,x1-1,-1);
		else	make(i,x1,x-1,1);
		if(y<y1)
			make(i,y+1,y1,1);
		else	make(i,y1+1,y,-1);
	}
	for(int i=1;i<=num;i++)
		cout<<s[i]<<"\n";
	return 0;
}
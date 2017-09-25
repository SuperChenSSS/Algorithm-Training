#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 100000
struct Node
{
	ll l,r;//线段树的左右整点
	ll c;//c用来记录重叠情况
	ll cnt,lf,rf;
	//cnt用来计算实在的长度，rf,lf分别是对应的左右真实的浮点数端点 
}segTree[MAXN*3];     
struct Line
{
	ll x,y1,y2;
	ll f;
}line[MAXN];
//把一段段平行于y轴的线段表示成数组，
//x是线段的x坐标，y1,y2线段对应的下端点和上端点的坐标 
//一个矩形 ，左边的那条边f为1，右边的为-1，
//用来记录重叠情况，可以根据这个来计算，nod节点中的c 

bool cmp(Line a,Line b)//sort排序的函数
{
	return a.x < b.x;
}     

double y[MAXN];//记录y坐标的数组
void Build(ll t,ll l,ll r)//构造线段树
{
	segTree[t].l=l;segTree[t].r=r;
	segTree[t].cnt=segTree[t].c=0;
	segTree[t].lf=y[l];
	segTree[t].rf=y[r];
	if(l+1==r)  return;
	ll mid=(l+r)>>1;
	Build(t<<1,l,mid);
	Build(t<<1|1,mid,r);//递归构造 
}     
void calen(ll t)//计算长度
{
	if(segTree[t].c>0)
	{
		segTree[t].cnt=segTree[t].rf-segTree[t].lf;
		return;
	}    
	if(segTree[t].l+1==segTree[t].r)  segTree[t].cnt=0;
	else  segTree[t].cnt=segTree[t<<1].cnt+segTree[t<<1|1].cnt;
}     
void update(ll t,Line e)//加入线段e，后更新线段树
{
	if(e.y1==segTree[t].lf&&e.y2==segTree[t].rf)
	{
		segTree[t].c+=e.f;
		calen(t);
		return;
	}    
	if(e.y2<=segTree[t<<1].rf)  update(t<<1,e);
	else if(e.y1>=segTree[t<<1|1].lf)  update(t<<1|1,e);
	else
	{
		Line tmp=e;
		tmp.y2=segTree[t<<1].rf;
		update(t<<1,tmp);
		tmp=e;
		tmp.y1=segTree[t<<1|1].lf;
		update(t<<1|1,tmp);
	}    
	calen(t);
}    
int main()
{
	ll i,n,t;
	ll x1,y1,x2,y2;
	while(scanf("%lld",&n)==1&&n)
	{
		t=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
			line[t].x=x1;
			line[t].y1=y1;
			line[t].y2=y2;
			line[t].f=1;
			y[t]=y1;
			t++;
			line[t].x=x2;
			line[t].y1=y1;
			line[t].y2=y2;
			line[t].f=-1;
			y[t]=y2;
			t++;
		} 
		sort(line+1,line+t,cmp);
		sort(y+1,y+t);   
		Build(1,1,t-1);
		update(1,line[1]);
		ll res=0;
		for(i=2;i<t;i++)
		{
			res+=segTree[1].cnt*(line[i].x-line[i-1].x);
			update(1,line[i]);
		}    
		printf("%lld\n",res);
	}    
	if(n==0)
		printf("*\n");
	return 0;
}
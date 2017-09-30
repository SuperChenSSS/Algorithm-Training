#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n;
struct node
{
	double x;
	double y;
}p[100005];
int a[100005];
double cmpx(node a,node b)
{
	return a.x<b.x;
}
double cmpy(int a,int b)
{
	return p[a].y<p[b].y;
}
double min(double a,double b)
{
	return a<b?a:b;
}
double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double find(int l,int r)
{
		 if(r==l+1)
			return dis(p[l],p[r]);
		 if(l+2==r)
			return min(dis(p[l],p[r]),min(dis(p[l],p[l+1]),dis(p[l+1],p[r])));
		 int mid=(l+r)>>1;
		 double ans=min(find(l,mid),find(mid+1,r));
		 int i,j,cnt=0;
		 for(i=l;i<=r;i++)
		 {
			 if(p[i].x>=p[mid].x-ans&&p[i].x<=p[mid].x+ans)
					a[cnt++]=i;
		 }
		 sort(a,a+cnt,cmpy);
		 for(i=0;i<cnt;i++)
		 {
			 for(j=i+1;j<cnt;j++)
			 {
				 if(p[a[j]].y-p[a[i]].y>=ans) break;
				 ans=min(ans,dis(p[a[i]],p[a[j]]));
			 }
		 }
		 return ans;
}
int main()
{
		//freopen("3.txt","r",stdin);
		int t;
		scanf("%d",&t);
		while(t--)
		{
				int n;
				cin>>n;
				for(int i=0;i<n;i++)
					 scanf("%lf%lf",&p[i].x,&p[i].y);
				sort(p,p+n,cmpx);
				printf("%.2lf\n",find(0,n-1));
		}
		return 0;
}
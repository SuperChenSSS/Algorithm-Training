#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const double PI=acos(-1);
typedef long long ll;
typedef pair<int,int> pi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
//debug
#define deb printf("begin\n");
#define dee printf("end\n");
#define def printf("find\n");
#define dey printf("Yes\n");
#define den printf("No\n");
#define dew printf("wrong\n");
void read(int&x){
	x=0;int f=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if (ch=='-')f=-1,ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
//--------------------------head--------------------------//

#define eps 1e-9
#define maxn 200005
struct Node{
	double x,y,ang;int v;Node(){}Node(double x,double y,int v):x(x),y(y),v(v){}
	void readin(){scanf("%lf%lf\n",&x,&y);read(v);ang=atan(y/x);}
	bool operator <(const Node&p)const{return ang<p.ang;}
}p[maxn];
int n,T;double x[maxn],y[maxn];int v[maxn];
ll sumL,sumR,ans;
void work(){
	read(n);rep(i,1,n)p[i].readin();sort(p+1,p+n+1);
	sumL=sumR=ans=0;rep(i,1,n)if (p[i].x>eps)sumL+=p[i].v;else sumR+=p[i].v;ans=sumL*sumR;
	rep(i,1,n){
		if (p[i].x>0)sumL-=p[i].v,sumR+=p[i].v;else sumL+=p[i].v,sumR-=p[i].v;
		ans=max(ans,sumL*sumR);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("H.in","r",stdin);
	freopen("H_.out","w",stdout);
	read(T);while (T--)work();return 0;
}


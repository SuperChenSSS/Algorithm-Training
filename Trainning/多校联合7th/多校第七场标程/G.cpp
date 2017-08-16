#include <cstdio>
#include <cstring>
#include <iostream>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define inf 1000000000
namespace maxflow{
	const int N=2455;
	int vol[N][N],rec[N],fir[N],pre[N],dis[N],cnt[N],cur,flag,tmp,ans,x,z;
	void init(){
		memset(vol,0,sizeof(vol));
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
	}
	void addedge(int x,int y,int z){
		vol[x][y]+=z;
		if(vol[x][y]>=inf) vol[x][y]=inf;
	}
	int maxflow(int n){
		rpt(i,1,n) fir[i]=1;
		cur=1;tmp=inf;ans=0;
		while(dis[1]<n){
			rec[cur]=tmp;flag=0;
			rpt(i,fir[cur],n) if(vol[cur][i]&&dis[i]==dis[cur]-1){
				flag=1;fir[cur]=i;
				tmp=std::min(tmp,vol[cur][i]);
				pre[i]=cur;cur=i;
				if(cur==n){
					ans+=tmp;
					if(ans>=inf) return inf;
					while(cur!=1){
						vol[pre[cur]][cur]-=tmp;
						vol[cur][pre[cur]]+=tmp;
						cur=pre[cur];
					}
					tmp=inf;
				}
				break;
			}
			if(flag) continue;
			z=n-1;
			rpt(i,1,n) if(vol[cur][i]&&dis[i]<z) z=dis[x=i];
			fir[cur]=x;
			if(!--cnt[dis[cur]]) break;
			cnt[dis[cur]=z+1]++;
			if(cur!=1) cur=pre[cur],tmp=rec[cur];
		}
		return ans;
	}
}
int T,n,m,k,w,x,y,z,ans;
int code(int r,int c){
	if(c==1) return 1;
	if(c==m+1) return n*(m-1)+2;
	return (r-1)*(m-1)+c;
}
int main(){
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		maxflow::init();
		rpt(i,1,n) rpt(j,1,m) scanf("%d",&w),maxflow::addedge(code(i,j),code(i,j+1),1000-w);
		rpt(i,1,k){
			scanf("%d%d%d",&x,&y,&z);
			rpt(i,1,m) if(i-z>1) maxflow::addedge(code(x,i),code(y,std::min(i-z,m+1)),inf);
		}
		ans=maxflow::maxflow(code(1,m+1));
		printf("%d\n",ans>=inf?-1:n*1000-ans);
	}
}

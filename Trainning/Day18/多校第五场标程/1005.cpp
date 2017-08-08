#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
using namespace std;
const int N=110000;
struct point{
	int x,y,pd;
}x[N*2];
int n,m,K,q,len;
int mi[N<<2],ma[N<<2];
long long lmi[N<<2],rmi[N<<2],lma[N<<2],rma[N<<2];
long long an[110000];
set<int>S[110000],SS;
int compare(point k1,point k2){
	return k1.x<k2.x;
}
long long golmi(int k1,int k2,int k3,int pre){
	if (pre<=mi[k1]) return 1ll*pre*(k3-k2+1);
	if (k2==k3) return mi[k1];
	int l=k1*2,r=k1*2+1,mid=(k2+k3)>>1;
	if (pre<=mi[r]) return 1ll*pre*(k3-mid)+golmi(l,k2,mid,pre);
	return golmi(r,mid+1,k3,pre)+lmi[k1];
}
long long gormi(int k1,int k2,int k3,int pre){
	if (pre<=mi[k1]) return 1ll*pre*(k3-k2+1);
	if (k2==k3) return mi[k1];
	int l=k1*2,r=k1*2+1,mid=(k2+k3)>>1;
	if (pre<=mi[l]) return 1ll*pre*(mid-k2+1)+gormi(r,mid+1,k3,pre);
	return gormi(l,k2,mid,pre)+rmi[k1];
}
long long golma(int k1,int k2,int k3,int pre){
	if (pre>=ma[k1]) return 1ll*pre*(k3-k2+1);
	if (k2==k3) return ma[k1];
	int l=k1*2,r=k1*2+1,mid=(k2+k3)>>1;
	if (pre>=ma[r]) return 1ll*pre*(k3-mid)+golma(l,k2,mid,pre);
	return golma(r,mid+1,k3,pre)+lma[k1];
}
long long gorma(int k1,int k2,int k3,int pre){
	if (pre>=ma[k1]) return 1ll*pre*(k3-k2+1);
	if (k2==k3) return ma[k1];
	int l=k1*2,r=k1*2+1,mid=(k2+k3)>>1;
	if (pre>=ma[l]) return 1ll*pre*(mid-k2+1)+gorma(r,mid+1,k3,pre);
	return gorma(l,k2,mid,pre)+rma[k1];
}
void change(int k1,int k2,int k3){
	int l=k1*2,r=k1*2+1,mid=k2+k3>>1;
	mi[k1]=min(mi[l],mi[r]);
	ma[k1]=max(ma[l],ma[r]);
	lmi[k1]=golmi(l,k2,mid,mi[r]);
	lma[k1]=golma(l,k2,mid,ma[r]);
	rmi[k1]=gormi(r,mid+1,k3,mi[l]);
	rma[k1]=gorma(r,mid+1,k3,ma[l]);
}
void init(int k1,int k2,int k3){
	if (k2==k3){
		set<int>::iterator k=S[k2].begin(); k++; mi[k1]=(*k);
		ma[k1]=0; 
	//	cout<<"fa "<<k2<<" "<<mi[k1]<<" "<<ma[k1]<<endl; 
		return;
	}
	int mid=k2+k3>>1;
	init(k1*2,k2,mid); init(k1*2+1,mid+1,k3);
	change(k1,k2,k3);
//	cout<<"ads "<<k1<<" "<<k2<<" "<<k3<<" "<<mi[k1]<<" "<<ma[k1]<<" "<<lmi[k1]<<" "<<rmi[k1]<<" "<<lma[k1]<<" "<<rma[k1]<<endl;
}
void changema(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		ma[k1]=k5; return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4) changema(k1*2,k2,mid,k4,k5); else changema(k1*2+1,mid+1,k3,k4,k5);
	change(k1,k2,k3);
}
void changemi(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		mi[k1]=k5; return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4) changemi(k1*2,k2,mid,k4,k5); else changemi(k1*2+1,mid+1,k3,k4,k5);
	change(k1,k2,k3);
}
int pr=0;
long long golmi(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5){
		long long ans=golmi(k1,k2,k3,pr); pr=min(pr,mi[k1]); return ans;
	}
	int mid=k2+k3>>1;
	return golmi(k1*2+1,mid+1,k3,k4,k5)+golmi(k1*2,k2,mid,k4,k5);
}
long long golma(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5){
		long long ans=golma(k1,k2,k3,pr); pr=max(pr,ma[k1]); return ans;
	}
	int mid=k2+k3>>1;
	return golma(k1*2+1,mid+1,k3,k4,k5)+golma(k1*2,k2,mid,k4,k5);
}
long long gormi(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5){
		long long ans=gormi(k1,k2,k3,pr); pr=min(pr,mi[k1]); return ans;
	}
	int mid=k2+k3>>1;
	return gormi(k1*2,k2,mid,k4,k5)+gormi(k1*2+1,mid+1,k3,k4,k5);
}
long long gorma(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5){
		long long ans=gorma(k1,k2,k3,pr); pr=max(pr,ma[k1]); return ans;
	}
	int mid=k2+k3>>1;
	return gorma(k1*2,k2,mid,k4,k5)+gorma(k1*2+1,mid+1,k3,k4,k5);
}
map<int,int>M[110000];
void solve(){
	scanf("%d%d%d%d",&n,&m,&K,&q); len=0;
	assert(1<=n&&n<=100000&&1<=m&&m<=100000&&1<=K&&K<=100000&&1<=q&&q<=100000);
	for (int i=1;i<=m;i++) S[i].clear(),S[i].insert(0),S[i].insert(n+1),M[i].clear();
	for (int i=1;i<=K;i++){
		len++; scanf("%d%d",&x[i].x,&x[i].y); x[i].pd=0;
		S[x[i].y].insert(x[i].x);
		assert(M[x[i].y][x[i].x]==0);
		M[x[i].y][x[i].x]=1;
	}
	for (int i=1;i<=q;i++){
		len++; scanf("%d%d",&x[len].x,&x[len].y); x[len].pd=i;
		assert(M[x[len].y][x[len].x]==0);
	}
	sort(x+1,x+len+1,compare);
	int now=1,pre=1;
	init(1,1,m);
	for (int nowx=1;nowx<=n;nowx++){
		SS.clear();
		while (now<=len&&x[now].x==nowx) now++;
	//	cout<<"asd "<<nowx<<" "<<pre<<" "<<now<<" "<<x[now].x<<endl;
		for (int i=pre;i<now;i++)
			if (x[i].pd==0){
				changema(1,1,m,x[i].y,x[i].x);
				SS.insert(x[i].y);
			}
		SS.insert(0); SS.insert(m+1);
		for (int i=pre;i<now;i++)
			if (x[i].pd){
			//	cout<<"now "<<x[i].pd<<endl;
				pr=n+1; long long ans=golmi(1,1,m,1,x[i].y); //cout<<ans<<" ";
				pr=n+1; ans+=gormi(1,1,m,x[i].y,m); //cout<<ans<<" ";
				pr=0; ans-=golma(1,1,m,1,x[i].y);// cout<<ans<<" ";
				pr=0; ans-=gorma(1,1,m,x[i].y,m);//a cout<<ans<<endl;
				set<int>::iterator k=S[x[i].y].lower_bound(x[i].x);
				int r=(*k); k--; int l=(*k);
				ans-=(r-l);
				k=SS.lower_bound(x[i].y); r=(*k); k--; l=(*k);
				ans-=(r-l-1);
				an[x[i].pd]=ans;
			} 
		for (int i=pre;i<now;i++)
			if (x[i].pd==0){
				set<int>::iterator k=S[x[i].y].upper_bound(x[i].x);
				changemi(1,1,m,x[i].y,(*k));
			}
		pre=now;
	}
	//cerr<<"en"<<endl;
	for (int i=1;i<=q;i++) printf("%lld\n",an[i]);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data1.out","w",stdout);
	int t; scanf("%d",&t); assert(1<=t&&t<=100);
	for (;t;t--) solve();
	return 0;
}

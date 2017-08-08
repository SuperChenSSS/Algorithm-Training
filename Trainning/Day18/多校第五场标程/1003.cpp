#include<iostream>
#include<cmath>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
struct tree{
	int l,r,size,ti,w;
	long long num;
}t[1010000];
int root,len,tot,num,preroot;
map<int,int>M;
queue<int>Q;
int getrand(){
	return (rand()<<14)+rand();
}
int getnew(){
	if (!Q.empty()){
		int where=Q.front(); Q.pop(); return where;
	}
	return ++len;
}
void change(int k1){
	t[k1].size=t[t[k1].l].size+t[t[k1].r].size+1;
	t[k1].num=t[t[k1].l].num+t[t[k1].r].num+t[k1].w;
}
int merge(int k1,int k2){
	if (k1==0||k2==0) {
		if (k1==0&&k2==0) return 0;
		int now=getnew(); t[now]=t[k1+k2]; t[now].ti=0; t[t[now].l].ti++; t[t[now].r].ti++;
		return now;
	}
	int now=getnew(); 
	if (getrand()%(t[k1].size+t[k2].size)<t[k1].size){
		t[now]=t[k1]; t[now].ti=0; t[now].r=merge(t[k1].r,k2);
	} else {
		t[now]=t[k2]; t[now].ti=0; t[now].l=merge(k1,t[k2].l);
	}
	change(now); t[t[now].l].ti++; t[t[now].r].ti++; return now;
}
void split(int k1,int k2,int &k3,int &k4){
	if (k1==0){
		k3=k4=0; return;
	}
	int now=getnew(); t[now]=t[k1]; t[now].ti=0;
	if (t[t[k1].l].size>=k2){
		k4=now; split(t[k1].l,k2,k3,t[now].l);
	} else {
		k3=now; split(t[k1].r,k2-t[t[k1].l].size-1,t[now].r,k4);
	}
	t[t[now].l].ti++; t[t[now].r].ti++;
	change(now);
}
void del(int k1){
	if (k1==0||t[k1].ti) return;
	t[t[k1].l].ti--; del(t[k1].l);
	t[t[k1].r].ti--; del(t[k1].r);
	Q.push(k1); tot++;
}
int mul(int k1,int k2){
	int k3=0; int where=getnew(); t[where]=t[k1]; t[where].ti=0;
	t[t[where].l].ti++; t[t[where].r].ti++; k1=where;
	while (k2){
		if (k2&1){
			int pre=k3; k3=merge(k3,k1); del(pre);
		}
		int pre=k1; k1=merge(k1,k1); del(pre); k2>>=1;
	}
	del(k1);
	return k3;
}
int getout(int root,int l,int r){
	int k1,k2,k3; split(root,r,k2,k3); int pre=k2; split(k2,l-1,k1,k2);
	del(k1); del(k3); del(pre);
	return k2;
}
void print(int k1){
	if (k1==0) return;
	cout<<k1<<" "<<t[k1].l<<" "<<t[k1].r<<" "<<t[k1].w<<" "<<t[k1].ti<<endl; 
	print(t[k1].l); print(t[k1].r);
}
int n,m,A[210000];
void calc(int k){
	if (k==0) return;
	if (M[t[k].w]==0) M[t[k].w]=1,num++;
	calc(t[k].l); calc(t[k].r);
}
void solve(){
	memset(t,0x00,sizeof t);
	scanf("%d%d",&n,&m); while (!Q.empty()) Q.pop();
	assert(1<=n&&n<=200000&&1<=m&&m<=200000);
	for (int i=1;i<=n;i++){
		scanf("%d",&A[i]); assert(0<=A[i]&&A[i]<=1000000000);
	}
	root=0; len=0; 
	for (int i=1;i<=n;i++){
		t[++len]=(tree){0,0,1,0,A[i],A[i]}; int pre=root,now=len; root=merge(root,len);
		del(pre); del(now);
	}
	preroot=merge(root,0);
	for (;m;m--){
		int k1; scanf("%d",&k1); 
		assert(1<=k1&&k1<=3);
		//if (m%1000==0) cerr<<m<<" "<<len<<" "<<tot<<endl;
		//cerr<<k1<<" "<<len<<" "<<Q.size()<<endl;
	//	if (m%10000==0){
	//		M.clear(); num=0; calc(root); cerr<<num<<endl; int ans=0;
	//	}
		if (k1==1){
			int l,r; scanf("%d%d",&l,&r); assert(1<=l&&l<=r&&r<=n);
			int ro=getout(root,l,r); 
			printf("%lld\n",t[ro].num);
			del(ro);
		} else if (k1==2){
			int l,r,K,ro,ro2; scanf("%d%d%d",&l,&r,&K);
			assert(1<=K&&K<l&&l<=r&&r<=n);
			if (K>r-l){
				ro=getout(root,l-K,r-K);
			} else {
				ro=getout(root,l-K,l-1),ro2=getout(root,l-K,l-K+(r-l+1)%K-1);
				int pre=ro; ro=mul(ro,(r-l+1)/K);
				del(pre); pre=ro;
				ro=merge(ro,ro2);
				del(ro2); del(pre);
			}
			int k1,k2,k3; split(root,r,k2,k3);  int pre=k2;
			split(k2,l-1,k1,k2);
			del(k2); del(root); del(pre);
			root=merge(ro,k3); pre=root;
			root=merge(k1,root);
			del(k1); del(ro); del(k3); del(pre);
		} else if (k1==3){
			int l,r; scanf("%d%d",&l,&r); assert(1<=l&&l<=r&&r<=n);
			int mid=getout(preroot,l,r);
			int k1,k2,k3; split(root,r,k2,k3); int pre=k2;
			split(k2,l-1,k1,k2);
			del(k2); del(root); del(pre);
			root=merge(mid,k3); pre=root;
			root=merge(k1,root);
			del(k1); del(mid); del(k3); del(pre);
		}
	}
	return;
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	solve();
	return 0;
}

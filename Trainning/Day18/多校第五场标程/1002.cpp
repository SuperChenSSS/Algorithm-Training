#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cassert>
using namespace std;
char s[10][30];
queue<int>Q;
int go[2][200][2],w[2][200],len1,len2,len;
struct tree{
	int go[2],father,w;
}t[200],T[200];
int n;
int get(int pd){
	len=0; memset(t,0x00,sizeof t);
	for (int where=1;where<=n;where++){
		int now=0,L=strlen(s[where]+1);
		for (int i=1;i<=L;i++){
			int k=s[where][i]-'0';
			if (t[now].go[k]==0) t[now].go[k]=++len;
			now=t[now].go[k];
		}
		t[now].w|=(1<<where-1);
	}
	for (int i=0;i<2;i++)
		if (t[0].go[i]) Q.push(t[0].go[i]);
	while (!Q.empty()){
		int k=Q.front();
		t[k].w|=t[t[k].father].w;
		for (int i=0;i<2;i++){
			int j=t[k].go[i];
			if (j==0) t[k].go[i]=t[t[k].father].go[i];
			else {
				t[j].w|=t[k].w; t[j].father=t[t[k].father].go[i];
				Q.push(j);
			}
		}
		Q.pop();
	}
	for (int i=0;i<=len;i++){
		go[pd][i][0]=t[i].go[0];
		go[pd][i][1]=t[i].go[1];
		w[pd][i]=t[i].w;
	}
	if (pd==0) memcpy(T,t,sizeof t);
	return len;
}
int val(int q,int l,int r){
	assert(l<=q&&q<=r);
}
const int mo=998244353;
int dp[2][70][130][130],m;
void update(int &k1,int k2){
	k1=(k1+k2)%mo;
}
void solve(){
	scanf("%d%d",&n,&m); val(n,1,6); val(m,1,100);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1); val(strlen(s[i]+1),1,20);
	}
	len1=get(0);
	for (int i=1;i<=n;i++){
		int L=strlen(s[i]+1);
		for (int j=1;j<=L;j++)
			if (L-j+1>j) swap(s[i][j],s[i][L-j+1]);
	}
	len2=get(1);
	for (int i=1;i<=n;i++){
		int L=strlen(s[i]+1);
		for (int j=1;j<=L;j++)
			if (L-j+1>j) swap(s[i][j],s[i][L-j+1]);
	}
	memset(dp,0x00,sizeof dp);
	int L=0;
	for (int i=1;i<=n;i++) L=max(L,(int)strlen(s[i]+1));
	L=min(L,m);
	for (int w=0;w<(1<<L);w++){
		int now=0,pd=0;
		for (int i=0;i<L;i++){
			int k=((w&(1<<i))>0); now=t[now].go[k]; pd|=t[now].w;
		}
		for (int i=L-1;i>=0;i--){
			int k=((w&(1<<i))==0); now=t[now].go[k]; pd|=t[now].w;
		}
		int k1=now; now=0;
		for (int i=L-1;i>=0;i--){
			int k=((w&(1<<i))>0); now=T[now].go[k];
		}
		dp[0][pd][now][k1]++;
	}
	int now=0;
	for (int i=L+1;i<=m;i++){
		int ne=now^1,w=0; memset(dp[ne],0x00,sizeof dp[ne]);
		for (int j=0;j<(1<<n);j++)
			for (int k1=0;k1<=len1;k1++)
				for (int k2=0;k2<=len2;k2++)
					if (w=dp[now][j][k1][k2])
						for (int k=0;k<2;k++){
							int k3=T[k1].go[k],k4=t[k2].go[k^1];
							update(dp[ne][j|T[k3].w|t[k4].w][k3][k4],w);
						}
		now=ne;
	}
	int ans=0;
	for (int i=0;i<=len1;i++)
		for (int j=0;j<=len2;j++)
			update(ans,dp[now][(1<<n)-1][i][j]);
	printf("%d\n",ans);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int t; scanf("%d",&t); val(t,1,5);
	for (;t;t--) solve();
	return 0;
}

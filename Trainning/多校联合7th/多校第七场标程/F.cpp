#include<cstdio>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define mo 1000000007
int p[8]={2,3,5,7,11,13,17,19};
int q[95]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,
233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};
int f[95+1][95+1][256],tag[95+1][95+1][256];
int f2[256][8+1],tag2[256][8+1];
int T,n,k,a,b,ans;
double h;
int subsolve(int sg,int k){int up,i,j,s,res;
	if(k>8) k=8;
	if(k<0) return 0;
	if(sg==0) return 1;

	if(tag2[sg][k]) return f2[sg][k];
	
	up=0;
	while((1<<up)<=sg) up++;
	up--;
	
	res=subsolve(sg^(1<<up),k);
	
	rpt(i,0,(1<<up)-1) if((sg&i)==i){
		s=p[up];
		rpt(j,0,up-1) if(i&(1<<j)){
			s*=p[j];
			if(s>n) break;
		}
		if(s<=n) (res+=subsolve(sg^(1<<up)^i,k-1))%=mo;
	}
	
	tag2[sg][k]=1;
	return f2[sg][k]=res;
}
int solve(int lim,int m,int k,int sg){int i,j,s,res;
	if(k<0) return 0;
	if(m<lim) return subsolve(sg,k);
	
	if(tag[m][k][sg]) return f[m][k][sg];
	
	res=solve(lim,m-1,k,sg);
	rpt(i,0,255) if((sg&i)==i){
		s=q[m];
		rpt(j,0,7) if(i&(1<<j)){
			s*=p[j];
			if(s>n) break;
		}
		if(s<=n) (res+=solve(lim,m-1,k-1,sg^i))%=mo;
	}
	
	tag[m][k][sg]=1;
	return f[m][k][sg]=res;
}
int main(){
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		memset(tag,0,sizeof(tag));
		memset(tag2,0,sizeof(tag2));
		if(k>95) k=95;
		h=sqrt(n)+1e-6;
		a=0;while(q[a]<=h) a++;
		b=0;while(q[b]<=n&&b<95) b++;
		ans=solve(a,b-1,k,(1<<a)-1)+solve(a,b-1,k-1,(1<<a)-1)-1;
		printf("%d\n",ans%mo);
	}
}

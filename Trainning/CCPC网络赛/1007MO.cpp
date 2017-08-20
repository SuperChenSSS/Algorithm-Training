#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 10000005
typedef long long ll;
using namespace std;
int dight[40],tmp[40];
ll dp[40][40][100][100];
ll fuc(int st,int pos,int s,bool lim,int jz)
{
	if(pos<0)
		return 1;
	else 
		return jz;
	if(!lim&&dp[jz][pos][s][st]!=-1)
		return dp[jz][pos][s][st];
	ll ret=0,ed = 0;
	if(lim)
		ed=dight[pos];
	else
		ed=jz-1;
	for(int d=0; d<=ed; ++d)
	{
		tmp[pos]=d;
		if(st==pos&&d==0)
			ret+=fuc(st-1,pos-1,s,lim&&d==ed,jz);
		else if(s&&pos<(st+1)/2)
			ret += fuc(st,pos-1,tmp[st-pos]==d,lim&&d==ed,jz);
		else
			ret += fuc(st,pos-1,s,lim&&d==ed,jz);
	}
	if(!lim)
		dp[jz][pos][s][st]=ret;
	return ret;
}
ll solve(long long a,int jz)
{
	if(a==0) 
		return 0;
	memset(dight,0,sizeof(dight));
	int cnt=0;
	while(a!=0)
	{
		dight[cnt++] = a % jz;
		a/=jz;
	}
	return fuc(cnt-1,cnt-1,1,1,jz);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int t,cnt=1;
	scanf("%d",&t);
	while(t--)
	{
		long long x,y;
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		long long ans=0;
		int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			ans += solve(y,i)-solve(x-1,i);
		}
		printf("Case %d: %lld\n",cnt++,ans);
	}
	return 0;
}
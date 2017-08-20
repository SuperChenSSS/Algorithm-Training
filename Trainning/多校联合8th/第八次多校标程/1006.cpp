#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MAXN=100005;

int tree[MAXN][26];
int fail[MAXN];
int g[2*MAXN];
int T,n,num,sum,m;
int dfn[MAXN],dep[MAXN],que[2*MAXN],fa[MAXN][25],leng[MAXN];
string s[MAXN];
int f[2*MAXN][25],id[2*MAXN][25];
vector<int> v[MAXN],va,vb;
queue<int> q;

void insert(string s)
{
	int dq=0,now;
	int len=s.size();
	for (int i=0;i<len;++i)
	{
		now=s[i]-'a';
		if (tree[dq][now]==0)
		{
			tree[dq][now]=++num;
			for (int j=0;j<26;++j) tree[num][j]=0;
			fail[num]=0;
		}
		leng[tree[dq][now]]=leng[dq]+1;
		dq=tree[dq][now];
	}
}

void build()
{
	while (!q.empty()) q.pop();
	for (int i=0;i<26;++i) 
	{
		if (tree[0][i]!=0) q.push(tree[0][i]);
	}
	while (!q.empty())
	{
		int dq=q.front();
		q.pop();
		for (int i=0;i<26;++i)
		{
			int now=tree[dq][i];
			if (now==0)
			{
				tree[dq][i]=tree[fail[dq]][i];
				continue;
			}
			q.push(now);
			int fa=fail[dq];
			while (fa!=0&&tree[fa][i]==0) fa=fail[fa];
			fail[now]=tree[fa][i];
		}
	}
}
void work(string s,vector<int> &v)
{
	int len=s.size();
	int dq=0,now;
	v.clear();
	for (int i=0;i<len;++i)
	{
		v.push_back(dq);
		now=s[i]-'a';
		dq=tree[dq][now];
	}
	v.push_back(dq);
}
void dfs(int x,int ga)
{
	++sum;que[sum]=x;dfn[x]=sum;
	fa[x][0]=ga;
	for (int i=1;i<=20;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=0;i<v[x].size();++i)
	{
		int y=v[x][i];
		if (y==ga) continue;
		dep[y]=dep[x]+1;dfs(y,x);
		++sum;que[sum]=x;
	}
}
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
int findl(vector<int> v,int d)
{
	int l=0,r=v.size()-1,mid,ans=-1;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (dfn[v[mid]]<=d)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if (ans==-1) ans=0;
	ans=v[ans];
	return ans;
}
int findr(vector<int> v,int d)
{
	int l=0,r=v.size()-1,mid,ans=-1;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (dfn[v[mid]]>=d)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if (ans==-1) ans=v.size()-1;
	ans=v[ans];
	return ans;
}
int lca(int x,int y)
{
	x=dfn[x];y=dfn[y];
	if (x>y) swap(x,y);
	int l=g[y-x+1];
	if (f[x][l]<f[y-(1<<l)+1][l]) return id[x][l];
	else return id[y-(1<<l)+1][l];
}
int main()
{
	scanf("%d",&T);
	for (int i=1;i<2*MAXN;++i) g[i]=(int)(log(1.0*i)/log(2));
    int countString = 0;
	while (T--)
	{
		scanf("%d",&n);
		num=0;leng[0]=0;
		for (int i=0;i<26;++i) tree[0][i]=0;
		for (int i=1;i<=n;++i)
		{
			cin>>s[i];
			insert(s[i]);
            countString += s[i].size();
		}
		build();
		for (int i=0;i<=num;++i) v[i].clear();
		for (int i=1;i<=num;++i) v[fail[i]].push_back(i); 
		sum=-1;dep[0]=1;dfs(0,-1);
		for (int i=0;i<=sum;++i) 
		{
			f[i][0]=dep[que[i]];id[i][0]=que[i];
		}
		for (int j=1;j<=g[sum+1];++j)
			for (int i=0;i+(1<<j)-1<=sum;++i)
			{
				if (f[i][j-1]<f[i+(1<<(j-1))][j-1])
				{
					f[i][j]=f[i][j-1];id[i][j]=id[i][j-1];
				}
				else
				{
					f[i][j]=f[i+(1<<(j-1))][j-1];id[i][j]=id[i+(1<<(j-1))][j-1];
				}
			}
		scanf("%d",&m);
		while (m--)
		{
			int x,y,ans=0;
			scanf("%d%d",&x,&y);
			work(s[x],va);work(s[y],vb);
			sort(va.begin(),va.end(),cmp);
			sort(vb.begin(),vb.end(),cmp);
			for (int i=0;i<va.size();++i)
			{
				x=va[i];
				y=findr(vb,dfn[x]);
				ans=max(ans,leng[lca(x,y)]);
				x=va[i];
				y=findl(vb,dfn[x]);
				ans=max(ans,leng[lca(x,y)]);
			}
			printf("%d\n",ans);
		}
	}
    assert(1 <= countString && countString <= 100000);
	return 0;
}

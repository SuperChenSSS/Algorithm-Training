#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn=100001;
int lens;
namespace SAM{
const int Len=maxn*2,Alp=26;
int pa[Len<<1],son[Len<<1][Alp],Right[Len<<1],fR[Len<<1];
int Max[Len<<1],cnt,root,last;
inline int Newnode(int _Max){++cnt;memset(son[cnt],0,sizeof(son[cnt]));Max[cnt]=_Max;return cnt;}
inline void pre(){cnt=Max[0]=0;root=last=Newnode(0);}
inline void sam(int alp)
{
    int np=son[last][alp],u=last,v,nv;
    if(np&&Max[np]==Max[last]+1){last=np;return;}
    np=Newnode(Max[last]+1);
    Right[np]=Max[last];
    fR[Max[last]]=np;
    while(u&&!son[u][alp])son[u][alp]=np,u=pa[u];
    if(!u)pa[np]=root;
    else
    {
        v=son[u][alp];
        if(Max[v]==Max[u]+1)pa[np]=v;
        else
        {
            nv=Newnode(Max[u]+1);   Right[nv]=-1;
            memcpy(son[nv],son[v],sizeof(son[v]));
            pa[nv]=pa[v],pa[v]=pa[np]=nv;
            while(u&&son[u][alp]==v)son[u][alp]=nv,u=pa[u];
        }
    }
    last=np;
}
char S[maxn*2+10];
vector<int>node[Len*2];
int dcnt=0,ls[Len*2],rs[Len*2],row[Len*2],fa[Len*2][19];
void predfs(int u)
{
	ls[u]=++dcnt;
	row[dcnt]=u;
	fa[u][0]=pa[u];
	for(int x=1;x<=18;x++)
		fa[u][x]=fa[fa[u][x-1]][x-1];
	for(auto& v:node[u])
		predfs(v);
	rs[u]=dcnt;
}
int test()
{
    pre();
    int len=strlen(S);
    for(int x=0;x<len;x++)
        {sam(S[x]-'a');}
	for(int x=0;x<=cnt;x++)node[x].clear();
	for(int x=0;x<=cnt;x++)
		node[pa[x]].pb(x);
	dcnt=0;
	predfs(1);
	Max[0]=-1;
    return len;
}
}

namespace tree{
int root[maxn*2],cnt,f[maxn];
const int magic1=maxn*20;
struct node{int l,r,sum;}tr[magic1];
void update(int l,int r,int x,int &y,int pos,int val)       //(l,r,root[x],root[x+1],pos)
{
	if(cnt+1>magic1-10){puts("tree");while(1);}
    tr[++cnt]=tr[x],tr[cnt].sum+=val,y=cnt;
    if(l==r)return;
    int mid=(l+r)/2;
    if(mid>=pos)update(l,mid,tr[x].l,tr[y].l,pos,val);
    else update(mid+1,r,tr[x].r,tr[y].r,pos,val);
}
int query(int l,int r,int x,int pos)
{
	if(pos<0)return 0;
    if(l==r)return tr[x].sum;
    int mid=(l+r)/2;
    if(mid>=pos)return query(l,mid,tr[x].l,pos);
    else return tr[tr[x].l].sum+query(mid+1,r,tr[x].r,pos);
}
}

namespace bit{
int root[maxn*4],cnt,len;
const int magic2=maxn*30;
struct node{int l,r,sum;}tr[magic2];
int newnode(){++cnt;tr[cnt].l=tr[cnt].r=tr[cnt].sum=0;return cnt;}
void update(int l,int r,int x,int pos,int val)
{
	if(cnt>magic2-10){puts("bit");while(1);}
    tr[x].sum+=val;
    if(l==r)return;
    int mid=(l+r)/2;
    if(mid>=pos){if(tr[x].l==0)tr[x].l=newnode();update(l,mid,tr[x].l,pos,val);}
    else{if(tr[x].r==0)tr[x].r=newnode();update(mid+1,r,tr[x].r,pos,val);}
}
int query(int l,int r,int x,int pos)
{
	if(pos<0)return 0;
    if(l==r)return tr[x].sum;
    int mid=(l+r)/2;
    if(mid>=pos)return query(l,mid,tr[x].l,pos);
    else return tr[tr[x].l].sum+query(mid+1,r,tr[x].r,pos);
}
void change(int a,int b)
{
	int t=b-tree::f[a];
	tree::f[a]=b;
	for (int x=SAM::ls[SAM::fR[a]]; x&&x<=len; x+=x&-x)
	{
		update(0,lens-1,root[x],a,t);
	}
}
int queryr(int a, int b, int c, int d)
{
	int ans=0;
    for (int x=b; x; x^=x&-x)
		ans+=query(0,lens-1,root[x],d)-query(0,lens-1,root[x],c-1);
	for (int x=a-1; x; x^=x&-x)
		ans-=query(0,lens-1,root[x],d)-query(0,lens-1,root[x],c-1);
    return ans;
}
}

int query(int A,int B,int C,int D)
{
	int t=SAM::fR[B],len=B-A+1;
	for(int x=18;x>=0;x--)
		if(len<=SAM::Max[SAM::fa[t][x]])
			t=SAM::fa[t][x];
	int a=SAM::ls[t],b=SAM::rs[t];
	int c=C+len-1,d=D;
	if(c>d)return 0;

    int ans=bit::queryr(a,b,c,d)+
    (tree::query(0,lens-1,tree::root[b],d)-tree::query(0,lens-1,tree::root[b],c-1))
    -(tree::query(0,lens-1,tree::root[a-1],d)-tree::query(0,lens-1,tree::root[a-1],c-1));

    return ans;
}
int main()
{
    //freopen("true_in.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
	int size = 256 << 20; // 256MB
	char *pp = (char*)malloc(size) + size;
	//__asm__("movl %0, %%esp\n" :: "r"(pp));
	int CASE;
	scanf("%d",&CASE);
	while(CASE--)
	{
    scanf("%s",SAM::S);
    lens=strlen(SAM::S);
    scanf("%s",SAM::S+lens);
    SAM::test();
    bit::len=SAM::cnt;
    for(int x=0;x<lens;x++)
		scanf("%d",&tree::f[x]);
	tree::cnt=0;
	tree::root[0]=tree::root[1]=tree::tr[0].l=tree::tr[0].r=tree::tr[0].sum=0;
	for(int x=2;x<=SAM::dcnt;x++)
		if(SAM::Right[SAM::row[x]]<lens&&SAM::Right[SAM::row[x]]!=-1)
			tree::update(0,lens-1,tree::root[x-1],tree::root[x],SAM::Right[SAM::row[x]],tree::f[SAM::Right[SAM::row[x]]]);
		else
			tree::root[x]=tree::root[x-1];
	int qu;
	scanf("%d",&qu);
	bit::cnt=0;
	bit::tr[0].l=bit::tr[0].r=bit::tr[0].sum=0;
	for(int x=1;x<=bit::len;x++)
		bit::root[x]=bit::newnode();
	int ans=0;
	for(int x=1;x<=qu;x++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a^=ans;b^=ans;
			bit::change(a,b);
		}
		else if(t==2)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a^=ans;b^=ans;c^=ans;d^=ans;
			if(b-a>d-c)
				ans=0;
			else
				ans=query(a+lens,b+lens,c,d);
			printf("%d\n",ans);
		}
	}
	}
    return 0;
}

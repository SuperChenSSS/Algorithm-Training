#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct hehe{int to,next;}e[6005];
int h[1005],cnt;
int dfn[1005],low[1005],vst[1005];
int sta[500005],instack[1005];
int val[1005],top,Index,color;
int map[1005][1005],rd[1005];
int T,n,m;
void init()
{
    memset(vst,0,sizeof(vst));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    memset(h,0,sizeof(h));
    memset(map,0,sizeof(map));
    memset(rd,0,sizeof(rd));
    top=0;cnt=0;Index=0;color=0;
}
void add(int x,int y)
{
    cnt++;e[cnt].to=y;e[cnt].next=h[x];h[x]=cnt;
}
void dfs(int u)
{
    dfn[u]=low[u]=++Index;
    sta[++top]=u;
    int i,v;
    instack[u]=vst[u]=1;
    for(i=h[u];i;i=e[i].next)
    {
        v=e[i].to;
        if(!vst[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else
            if(instack[v])
                low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        color++;
        do
        {
            v=sta[top--];
            instack[v]=0;
            val[v]=color;
        }while(v!=u);
    }
}
int q[100005];
bool solve()
{
    int i,j,jj,y;
    for(i=1;i<=n;i++)
        if(!vst[i])
            dfs(i);
    for(i=1;i<=n;i++)
        for(j=h[i];j;j=e[j].next)
        {
            y=e[j].to;
            if(val[i]!=val[y])
                map[val[i]][val[y]]=1;
        }
    if(color==1) return false;
    for(i=1;i<=color;i++)
        for(j=1;j<=color;j++)
            if(map[j][i]) rd[i]++; 
    for(i=1;i<=color;i++)
    {
        for(j=1;j<=color;j++)
            if(map[i][j]) break;
        for(jj=1;jj<=color;jj++)
            if(map[jj][i]) break;
        if(j>color&&jj>color) return true;
    }
    memset(vst,0,sizeof(vst));
    q[0]=0;
    for(i=1;i<=color;i++)
        if(rd[i]==0)
        {
            q[0]++;
            q[q[0]]=i;
            vst[i]=1;
        }
    if(q[0]>=2) return true;
    int t=1,x,num;
    while(t<=q[0])
    {
        x=q[t];
        num=0;
        for(i=1;i<=color;i++)
        {
            if(vst[i]) continue;
            if(!map[x][i]) continue;
            rd[i]--;
            if(rd[i]==0)
            {
                num++;
                q[0]++;
                q[q[0]]=i;
                vst[i]=1;
                if(num==2) return true;
            }
        }
        t++;
    }
    return false;
}
int main()
{
    int i,x,y;
    cin>>T;
    while(T--)
    {
        init();
        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            add(x,y);
        }
        if(solve())
            puts("Light my fire!");
        else
            puts("I love you my love and our love save us!");
    }
    return 0;
}
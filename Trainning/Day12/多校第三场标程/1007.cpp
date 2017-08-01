#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,id[2005],f[2005],G[10][2],One,Zero,st,size[2005],tot,cnt[2],y; 
vector<pair<int,pair<int,int> > >ans;

char c[1005];

void dfs(int x,int t)
{
        size[t]=0; 
        if (x==m)
        {
            if (f[t-(1<<m)]==st) ++size[t];
        } 
        else 
        {
                dfs(x+1,t<<1);
                dfs(x+1,(t<<1)|1);
                size[t]=size[t<<1]+size[(t<<1)|1];
        }
        if(size[t]) id[t]=++tot; 
}

void Output(int x,int t)
{
        if (!size[t]) return;
        if (id[t]&&x>0)
        {
                int fa=t>>1;
                ans.pb(mk(id[fa],mk(G[x][t&1],id[t])));
                //printf("%d %d %d\n",id[fa],G[x][t&1],id[t]);
        }
        if (x==m)
        {
                if (id[t]) ans.pb(mk(id[t],mk(One,m+1)));//printf("%d %d %d\n",id[t],One,n+1);
        }
        else 
        {
                Output(x+1,t<<1);
                Output(x+1,(t<<1)|1);
        }
}

int main()
{ 
        for (;scanf("%d",&m)!=EOF;)
        {
                ans.clear(); 
                memset(id,0,sizeof(id));
                cnt[0]=cnt[1]=0;
                for (i=0;i<(1<<m);++i)
                {
                        scanf("%s%d",c,&y); int x=0;
                        for (j=0;j<strlen(c);++j) x=(x<<1)+c[j]-'0';
                        f[x]=y;
                        cnt[y]++;
                }
                if (cnt[0]>cnt[1]) st=1; else st=0;
                tot=m+1;
                for (i=1;i<=m;++i) G[i][0]=++tot,G[i][1]=++tot;
                dfs(0,1);
                One=++tot; Zero=++tot;
                printf("%d\n",st^1);
                printf("%d\n",tot-(m+1));
                for (i=m+2;i<=tot;++i) 
                {
                        int flag=0;
                        if (i==One||i==id[1]) flag=1;
                        for (j=1;j<=m;++j) if (i==G[j][0]) flag=1;
                        if (flag==1) puts("1");
                        else puts("0");
                }
                for (i=1;i<=m;++i)
                {
                        ans.pb(mk(i,mk(One,G[i][1])));
                        ans.pb(mk(G[i][1],mk(One,G[i][0])));
                }
                Output(0,1); 
                printf("%d\n",ans.size());
                for (i=0;i<(int)ans.size();++i)
                    printf("%d %d %d\n",ans[i].fi,ans[i].se.fi,ans[i].se.se); 
        }
}

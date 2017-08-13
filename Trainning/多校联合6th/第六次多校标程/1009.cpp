//#include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 1e5 + 10;
int T , n , link[N];
vi g[N];

template<class T>
struct Fenwick{
#define lb(x) ((x)&-(x))
    int n;T a[N];
    void ini(int _n){ fill_n(a+1,n=_n,0);}
    void add(int x,T d){ for(;x<=n;x+=lb(x)) a[x]+=d;}
    void add(int l,int r,T d){ add(l,d),add(r+1,-d);}
    T sum(int x){ T r=0;for(;x>=1;x^=lb(x)) r+=a[x];return r;}
    T sum(int l,int r){return sum(r) - sum(l-1);}
};

struct LCARMQ{
    static const int N = ::N << 1;
    int a[20][N] , lft[N] , dep[N] , lg[N] , L;
    int rmin(int x,int y){return dep[x] < dep[y] ? x : y;}
    void add(int x){ a[0][L++] = x;}
    Fenwick<ll> dis;
    int dfsleft[N],dfsright[N],w[N],_;
    void dfs(int c,int fa=0){
        dfsleft[c] = ++_;
        lft[c]=L;add(c);
        for(auto t : g[c]) if(t!=fa) dep[t]=dep[c]+1,dfs(t,c),add(c);
        dfsright[c] = _;
    }
    void Build(){
        _ = L = 0;dfs(1);
        dis.ini(n);
        rep(i,2,n+1) dis.add(dfsleft[i],dfsright[i],w[i]=1);
        rep(i,2,L) lg[i]=lg[i>>1]+1;
        rep(i,1,20){
            int lim = L+1-(1<<i);
            rep(j,0,lim) a[i][j] = rmin(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
        }
    }
    int lca(int x,int y){
        x = lft[x] , y = lft[y];
        if(x > y) swap(x , y);
        int i = lg[y-x+1];
        return rmin(a[i][x] , a[i][y+1-(1<<i)]);
    }
    ll Dep(int x){return dis.sum(dfsleft[x]);}
    ll Dis(int u,int v){
        return Dep(u) + Dep(v) - 2 * Dep(lca(u,v));
    }
    void modify(int x,int K){dis.add(dfsleft[x],dfsright[x],K-w[x]);w[x]=K;}
};

namespace Centriod {
    int vis[N],sz[N],par[N],dep[N];
    ll disA[N][2] , cnt[N];
    int belong[20][N],top[20][N],lft[20][N],rgt[20][N],pl[20];
    Fenwick<ll> weight[20] , del[20];
    LCARMQ lca;
    void dfssz(int c,int fa,int Sz,int &rt){
        sz[c] = 1;
        for(auto t : g[c]) if(!vis[t]&&t!=fa) dfssz(t,c,Sz,rt) , sz[c]+=sz[t];
        if(!rt && sz[c]*2>Sz) rt=c;
    }
    void dfstree(int c,int fa,int rt,int layer){
        //cout << __FUNCTION__ << " " << c << " " << fa << " " << rt << " " << layer << endl;
        belong[layer][c] = rt;
        top[layer][c] = fa==rt?c:top[layer][fa];
        lft[layer][c] = ++pl[layer];
        for(auto t : g[c]) if(!vis[t]&&t!=fa) dfstree(t,c,rt,layer);
        rgt[layer][c] = pl[layer];
    }
    void dfs(int c,int lastrt=0,int layer=0){
        int rt=0;dfssz(c,0,0,rt);dfssz(c,0,sz[c],rt=0);
        dfstree(rt,0,rt,layer);
        vis[rt] = true;
        dep[rt] = layer;
        par[rt] = lastrt;
        for(auto t : g[rt]) if(!vis[t]) dfs(t,rt,layer+1);
    }
    void init(int n){
        rep(i,1,n+1) vis[i]=false , cnt[i]=0;
        rep(i,1,n+1) rep(j,0,2) disA[i][j]=0;
        rep(i,0,20) pl[i] = 0 , weight[i].ini(n) , del[i].ini(n);
        lca.Build();
        dfs(1);
    }
    ll query(int x){
        ll res = disA[x][0];
        for(int i=x,p=par[i],layer=dep[p];p;i=p,p=par[i],--layer){
            res += disA[p][0] - disA[i][1]
                + (cnt[p] - cnt[i]) * lca.Dis(x , p)
                + del[layer].sum(lft[layer][x]);
        }
        return res;
    }
    void modify_edge(int x,int K){
        int delK = lca.w[x] - K;
        lca.modify(x , K);
        int y = link[x];
        if(dep[y] < dep[x]) swap(x , y);
        for(int i=x,layer=dep[x];i;i=par[i],--layer){
            int t = lft[layer][x] > lft[layer][y] ? x : y;
            int A = belong[layer][t] , B = top[layer][t];
            ll S = weight[layer].sum(lft[layer][A] , lft[layer][B] - 1)
                + weight[layer].sum(rgt[layer][B] + 1 , rgt[layer][A]);
            del[layer].add(lft[layer][t] , rgt[layer][t] , S * delK);
        }
    }
    void modify_vertex(int x,int K){
        for(int i=x,p=par[i],layer=dep[i];i;i=p,p=par[i],--layer){
            cnt[i] += K;
            weight[layer].add(lft[layer][x],K);
            if(p){
                ll A = lca.Dis(x , p) * K;
                disA[i][1] += A;
                disA[p][0] += A;
            }
        }
    }
};


int main(){
    scanf("%d",&T);
    rep(i,0,T) {
        scanf("%d",&n);
        rep(i,1,n+1) g[i].clear();
        rep(i,2,n+1) {
            scanf("%d",link + i);
            g[link[i]].pb(i);
            g[i].pb(link[i]);
        }
        Centriod::init(n);
        int m;
        scanf("%d",&m);
        rep(i,0,m){
            int op,u,K;
            scanf("%d%d",&op,&u);
            if(op == 1) printf("%lld\n",Centriod::query(u));
            else{
                scanf("%d",&K);
                if(op == 2) Centriod::modify_edge(u , K);
                else Centriod::modify_vertex(u , K);
            }
        }
    }
    return 0;
}

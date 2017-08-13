#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const    int N = 300005;
const    int P = 1e9 + 7;
const    int inf = 1e9;
const    LL Inf = 1e15;

inline int IN(){
    char ch = getchar(); int x = 0, f = 0;
    while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
    while(ch >= '0' && ch <= '9'){
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
    int an = 1;
    for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
    return an;
}

void renew(int &x, int y){
    x += y;
    if(x < 0) x += P;
    else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
    freopen((a + ".in").c_str(), "r", stdin);
    freopen((a + ".out").c_str(), "w", stdout);
#else
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n, k;
LL f[300005], g[300005];
struct edge{
    int v, pre;
}e[600005];
int adj[300005], dex;
int fa[300005], ID[300005], dep[300005], lg[300005];
int Min[20][300005], st[300005], ed[300005], cnt;
LL PreMin[300005], SufMin[300005];
int A[300005], per[300005];

int min_dep(int x, int y){
    return dep[x] < dep[y];
}

int lca(int x, int y){
    if(st[x] > st[y]) swap(x, y);
    if(ed[x] >= ed[y]) return x;
    int t = lg[st[y] - st[x] + 1];
    return fa[min(Min[t][st[x]], Min[t][st[y] - (1 << t) + 1], min_dep)];
}

void work(int l, int r){
    if(l == r) return;
    int md = (l + r) / 2;
    work(l, md);
    A[md] = per[md];
    A[md + 1] = per[md + 1];
    PER(i, md - 1, l) A[i] = lca(per[i], A[i + 1]);
    REP(i, md + 2, r) A[i] = lca(per[i], A[i - 1]);
    REP(i, md + 1, r) f[i] = min(f[i], g[md] + dep[A[i]]);
    PreMin[l] = 1LL << 60;
    SufMin[md + 1] = 1LL << 60;
    PER(i, md, l + 1) SufMin[i] = min(SufMin[i + 1], (i == l ? 1LL << 60 : g[i - 1]));
    REP(i, l + 1, md) PreMin[i] = min(PreMin[i - 1], (i == l ? 1LL << 60 : g[i - 1]) + dep[A[i]]);
    int t = lca(A[md], A[md + 1]), fen = md;
    while(fen > l && dep[A[fen]] > dep[t]) fen --;
    REP(i, md + 1, r){
        if(dep[A[i]] > dep[t]){
            f[i] = min(f[i], SufMin[fen + 1] + dep[t]);
            f[i] = min(f[i], PreMin[fen]);
        }else{
            while(fen > l && dep[A[fen]] > dep[A[i]]) fen --;
            f[i] = min(f[i], SufMin[fen + 1] + dep[A[i]]);
            f[i] = min(f[i], PreMin[fen]);
        }
    }
    work(md + 1, r);
}

void dfs(int x){
    st[x] = ++cnt;
    ID[cnt] = x;
    Min[0][cnt] = x;
    for(int i = adj[x]; i; i = e[i].pre){
        int v = e[i].v;
        if(v == fa[x]) continue;
        fa[v] = x;
        dep[v] = dep[x] + 1;
        dfs(v);
    }
    ed[x] = cnt;
}



int main(){

    n = 300000;
    lg[1] = 0;
    REP(i, 2, n) lg[i] = lg[i >> 1] + 1;
    
    while(scanf("%d%d", &n, &k) != EOF){

        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        memset(e, 0, sizeof e);
        memset(adj, 0, sizeof adj);
        memset(fa, 0, sizeof fa);
        memset(ID, 0, sizeof ID);
        memset(dep, 0, sizeof dep);
        memset(Min, 0, sizeof Min);
        memset(st, 0, sizeof st);
        memset(ed, 0, sizeof ed);
        memset(PreMin, 0, sizeof PreMin);
        memset(SufMin, 0, sizeof SufMin);
        memset(A, 0, sizeof A);
        memset(per, 0, sizeof per);
        dex = cnt = 0;



        REP(i, 1, n) scanf("%d", per + i);
        REP(i, 1, n - 1){
            int x, y;
            scanf("%d%d", &x, &y);
            e[++dex] = (edge){y, adj[x]}; adj[x] = dex;
            e[++dex] = (edge){x, adj[y]}; adj[y] = dex;
        }

        memset(g, 0x3f, sizeof g);
        g[0] = 0;

        dfs(dep[1] = 1);

        REP(dd, 1, 19){
            REP(i, 1, n - (1 << dd) + 1){
                Min[dd][i] = min(Min[dd - 1][i], Min[dd - 1][i + (1 << (dd - 1))], min_dep);
            }
        }

        REP(i, 1, k){
            memset(f, 0x3f, sizeof f);
            if(i == 1){
                int gt = per[1];
                REP(i, 1, n){
                    gt = lca(gt, per[i]);
                    f[i] = dep[gt];
                }
            } else work(1, n);
            memcpy(g, f, sizeof g);
        }

        printf("%lld\n", g[n]);
    }


#ifdef LOCAL
    cerr << endl << endl << "Time Spec = " << clock() / 1000. << "ms" << endl;
#endif
    return 0;
}
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
const    int N = 1000005;
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

inline int Pow(int x, LL y, int p){
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
LL w[N];
int dex;
int adj[N], fa[N], sz[N];
struct edge{
    int v, w, pre;
}e[N << 1];

int que[N], vis[N], r;
void bfs(int x){
    REP(i, 1, n) vis[i] = fa[i] = sz[i] = 0;
    que[r = vis[1] = 1] = x;
    REP(l, 1, r){
        int u = que[l];
        for(int i = adj[u]; i; i = e[i].pre){
            int v = e[i].v;
            if(!vis[v]) vis[que[++r] = v] = 1, fa[v] = u, w[v] = e[i].w;
        }
    }
    PER(i, r, 1){
        int u = que[i];
        sz[u] ++; sz[fa[u]] += sz[u];
    }
    LL ans = 0;
    REP(i, 1, n) ans += min(sz[i], k) * w[i];
    cout << ans << endl;
}

int main(){    
    int cas = 0;
    while(scanf("%d%d", &n, &k) != EOF){
        REP(i, 1, n) adj[i] = 0; dex = 0;
        REP(i, 1, n - 1){
            int x = IN(), y = IN(), w = IN();
            e[++dex] = (edge){y, w, adj[x]}; adj[x] = dex;
            e[++dex] = (edge){x, w, adj[y]}; adj[y] = dex;
        }
        bfs(1);
    }

#ifdef LOCAL
    cerr << endl << endl << "Time Spec = " << clock() / 1000. << "ms" << endl;
#endif
    return 0;
}
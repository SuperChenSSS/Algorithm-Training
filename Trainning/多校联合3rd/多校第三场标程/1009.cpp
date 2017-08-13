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
const    int N = 100005;
const    int P = 998244353;
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

int fac[200005], ifac[200005];
int D[405][405], E[405][405], m, cas;

void Main(){
    REP(i, 1, m) REP(j, 1, m) D[i][j] = 0;
    REP(i, 1, m) REP(j, 1, m) scanf("%d", &E[i][j]);
    int ans = 1;
    REP(i, 1, m){
        int res1 = 0, res2 = 0;
        REP(j, 1, m) res1 += E[j][i], res2 += E[i][j];
        if(res1 != res2){
            printf("Case #%d: 0\n", ++cas);
            return;
        }

        REP(j, 1, m) ans = (LL)ans * ifac[E[i][j]] % P;
        ans = (LL)ans * fac[res2 - 1] % P;
        if(i == 1) ans = (LL)ans * res2 % P;

        D[i][i] = res2;
        REP(j, 1, m) D[i][j] = (D[i][j] + P - E[i][j]) % P;
    }
    REP(i, 2, m){
        if(!D[i][i])
        REP(j, i + 1, m)if(D[j][i]){
            REP(k, 2, m) swap(D[j][k], D[i][k]);
            ans = P - ans;
        }
        if(!D[i][i]){
            printf("Case #%d: 0\n", ++cas);
            return;
        }
        ans = (LL)ans * D[i][i] % P;
        int iv = Pow(D[i][i], P - 2, P);
        REP(j, 2, m) if(j != i){
            int _ = P - (LL)D[j][i] * iv % P;
            REP(k, 2, m) D[j][k] = (D[j][k] + (LL)_ * D[i][k]) % P;
        }
    }
    printf("Case #%d: %d\n", ++cas, ans);
}

int main(){

    fac[0] = 1;
    REP(i, 1, 200001) fac[i] = (LL)fac[i - 1] * i % P;
    REP(i, 0, 200001) ifac[i] = Pow(fac[i], P - 2, P);

    while(scanf("%d", &m) != EOF) Main();


#ifdef LOCAL
    cerr << endl << endl << "Time Spec = " << clock() / 1000. << "ms" << endl;
#endif
    return 0;
}
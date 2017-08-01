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
    x = (x + y >= P ? x + y - P : x + y);
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

int m, b, c;
int len, fac[55];
char str[100005];
int dig[100005], stk[100005], top;

int Mod(){
    long long x = 0;
    PER(i, len, 1){
        x = (x * 10 + dig[i]);
        dig[i] = x / b;
        x %= b;
    }
    while(len && dig[len] == 0) len --;
    return x;
}

int dp[55][55][55];
int pw[55][55];
int ifac[55];
int ans[55];

void add(){
    stk[0] -= c;
    int now = 0;
    while(stk[now] >= b){
        stk[now] -= b;
        stk[now + 1] ++;
        now ++;
    }
    top = max(top, now + 1);
}

int fu;
void Minus(){
    stk[0] -= c;
    int now = 0;
    while(now < top && stk[now] < 0){
        stk[now] += b;
        stk[now + 1] --;
        now ++;
    }
    if(now >= top){
        fu = 1;
        return;
    }
    while(top && stk[top - 1] == 0) top --;
    if(!top){
        fu = 1;
        return;
    }
}

int cf[55], ncf[55];
int cmod;

void clear_all(){
    len = top = 0;
    memset(stk, 0, sizeof stk);
    memset(str, 0, sizeof str);
    memset(dig, 0, sizeof dig);
    memset(dp, 0, sizeof dp);
    memset(pw, 0, sizeof pw);
    memset(ans, 0, sizeof ans);
    fu = 0;
    memset(cf, 0, sizeof cf);
    memset(ncf, 0, sizeof ncf);
    cmod = 0;
}

void Main(){

    clear_all();

    c = 1 - c;
    cmod = (c % P + P) % P;
    scanf("%s", str + 1);
    
    len = strlen(str + 1);
    REP(i, 1, len) dig[i] = str[i] - 48;
    reverse(dig + 1, dig + len + 1);
    int nmod = 0;
    while(len > 0){
        stk[top] = Mod();
        top ++;
    }

    PER(i, top - 1, 0){
        nmod = ((LL)nmod * b + stk[i]) % P;
    }

    nmod = (nmod + P - 1 + m) % P;

    REP(i, 0, m) pw[0][i] = ifac[i];

    REP(i, 1, m){
        pw[i][0] = 1;
        int ww = Pow(b, i, P);
        REP(j, 1, m) pw[i][j] = (LL)pw[i][j - 1] * ww % P;
        REP(j, 0, m) pw[i][j] = (LL)pw[i][j] * ifac[j] % P;
    }

    dp[1][0][0] = 1;
    dp[0][0][0] = 1;
    REP(i, 1, m){
        REP(j, 0, i) REP(k, 0, m){
            const int val = dp[i][j][k];
            if(!val) continue;
            renew(dp[i + 1][j][k], val);
            REP(t, 0, m - k){
                int ddd = (t & 1 ? P - pw[i][t] : pw[i][t]);
                renew(dp[i + 1][j + 1][k + t], (LL)val * ddd % P);
            }
        }
    }

    REP(cho, 0, m){
        if(fu) break;
        int nowmod = nmod;
        int nowcho = 0;
        if(top - 1 > m){
            int xmod = nowmod;
            int *xdp = dp[m + 1][cho];
            int xx = (cho & 1 ? P - 1 : 1);
            REP(a, 0, m){
                int gt = (LL)xx * ifac[a] % P;
                REP(b, 0, m - a) {
                    ans[a + b] = (ans[a + b] + ((LL)xdp[b] * gt)) % P;
                }
                xx = (LL)xx * xmod % P;
            }
            nmod = (nmod + P - cmod) % P;
            if(c > 0) Minus();
            else add();
            continue;
        }
        PER(i, top - 1, 0){
            if(stk[i] > 1 && i != 0){
                int xmod = (nowmod + P - pw[i][1]) % P;
                int xcho = nowcho + 1;
                if(xcho <= cho){
                    int *xdp = dp[i][cho - xcho];
                    int xx = (cho & 1 ? P - 1 : 1);
                    REP(a, 0, m){
                        int gt = (LL)xx * ifac[a] % P;
                        REP(b, 0, m - a) {
                            ans[a + b] = (ans[a + b] + ((LL)xdp[b] * gt)) % P;
                        }
                        xx = (LL)xx * xmod % P;
                    }
                }
            }
            if(stk[i] > 0){
                int xmod = nowmod;
                int xcho = nowcho;
                if(xcho <= cho){
                    int *xdp = dp[i][cho - xcho];
                    int xx = (cho & 1 ? P - 1 : 1);
                    REP(a, 0, m){
                        int gt = (LL)xx * ifac[a] % P;
                        REP(b, 0, m - a) {
                            ans[a + b] = (ans[a + b] + ((LL)xdp[b] * gt)) % P;
                        }
                        xx = (LL)xx * xmod % P;
                    }
                }
            }
            if(stk[i] > 1) break;
            if(stk[i]){
                nowmod = (nowmod + P - pw[i][1]) % P;
                nowcho += (stk[i] > 0);
            }
        }
        nmod = (nmod + P - cmod) % P;
        if(c > 0) Minus();
        else add();
    }

    cf[0] = 1;
    memset(ncf, 0, sizeof ncf);
    REP(i, 0, m - 1){
        memcpy(ncf, cf, sizeof cf);
        memset(cf,  0,  sizeof cf);
        REP(j, 0, i){
            cf[j] = (cf[j] + (LL)ncf[j] * (P - i)) % P;
            cf[j + 1] = (cf[j + 1] + ncf[j]) % P;
        }
    }

    int res = 0;
    REP(i, 0, m) cf[i] = (LL)cf[i] * ifac[m] % P;
    REP(i, 0, m) res = (res + (LL)cf[i] * ans[i] % P * fac[i]) % P;
    static int cas = 0;
    printf("Case #%d: %d\n", ++cas, res); 
}

int main(){
    ifac[0] = fac[0] = 1;
    REP(i, 1, 53){
        ifac[i] = (LL)ifac[i - 1] * Pow(i, P - 2, P) % P;
        fac[i] = Pow(ifac[i], P - 2, P);
    }

    while(scanf("%d%d%d", &m, &b, &c) != EOF) Main();
}
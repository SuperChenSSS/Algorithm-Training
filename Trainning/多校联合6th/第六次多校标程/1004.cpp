// {{{
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

const int N = 210 , P[] = {(int)1e9 + 7 , 998244353};
int myrand(int j){return ((ll)rand()<<32^(ll)rand()<<16^rand())%P[j];}
int T,rd[2][N],n,par[N],hs[N],sz[N],tag[N],times;
vector<vi> v[2];

vector<vi> gethash(){
    vector<vi> v;
    rep(i,2,n+1) scanf("%d",par+i);
    rep(a,2,n+1) rep(b,a+1,n+1){
        vi u;
        rep(t,0,1){
            int *rd=::rd[t],P=::P[t];
            rep(i,1,n+1) sz[i]=1,hs[i]=1;
            tag[a]=tag[b]=tag[1]=++times;
            per(i,1,n+1) if(tag[i]!=times) sz[par[i]]+=sz[i];
            per(i,1,n+1){
                if(tag[i]==times) u.pb(hs[i]);
                else hs[par[i]]=1ll*hs[par[i]]*(rd[sz[par[i]]]+hs[i])%P;
            }
        }
        sort(all(u));
        v.pb(u);
    }
    return v;
}

bool solve(){
    scanf("%d",&n);
    rep(i,0,2) v[i]=gethash();
    sort(all(v[1]));
    for(auto e : v[0]) if(binary_search(all(v[1]),e)) return 1;
    return 0;
}

int main(){
    db t1=clock();
    srand(time(NULL));
    scanf("%d",&T);
    rep(i,0,2) rep(j,0,N) rd[i][j]=myrand(i);
    rep(i,0,T) puts(solve()?"YES":"NO");
    //cerr << "std : " << (clock() - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}

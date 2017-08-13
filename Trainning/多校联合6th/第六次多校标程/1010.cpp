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

const int N = 1e5 + 10;
int T,n,K,par[N],sz[N];

int main(){
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%d",&n,&K);
        rep(i,2,n+1) scanf("%d",par + i);
        rep(i,1,n+1) sz[i]=1;
        bool ok=1;
        per(i,1,n+1) ok&=sz[i]<=2,sz[par[i]]+=sz[i]&1;
        puts(n%2==0&&K>=n/2-1&&ok?"Bob":"Alice");
    }
    return 0;
}

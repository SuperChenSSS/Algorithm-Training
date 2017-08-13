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
int T,n,a[N],id[N];

int main(){
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d",&n);
        rep(i,1,n+1) scanf("%d",a+i),id[i]=i;
        sort(id+1,id+1+n,[&](int x,int y){return a[x]>a[y];});
        rep(i,2,n+1) {
            int f=0;
            rep(j,1,n+1) if(id[j]%i!=0){
                f=a[id[j]];
                break;
            }
            printf("%d%c",f," \n"[i==n]);
        }
    }
    return 0;
}

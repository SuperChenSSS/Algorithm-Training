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

typedef double T;
typedef complex<T> P;
db eps = 1e-8;

#define x(a) a.real()
#define y(a) a.imag()
db dis(P a,P b){return abs(a - b);}

P read(){
    db x,y;
    scanf("%lf%lf",&x,&y);
    return P(x,y);
}

P inv(P p,db r){
    return p * (r*r/norm(p));
}

P divide(P a,P b){
    P r = a + b;
    if(a == -b) r = P(-y(a) , x(a));
    return r / abs(r);
}

int main(){
    int T;
    scanf("%d",&T);
    rep(i,0,T){
        db r;scanf("%lf",&r);
        P p = read();
        P q = read();
        if(p == q) printf("%.7f\n",2 * (r - abs(p)) + eps);
        else if(sqrt(norm(p) - norm(p-q)/4) * r >= norm(p))
            printf("%.7f\n",2 * dis(divide(p,q)*r , p) + eps);
        else printf("%.7f\n",dis(inv(p,r) , inv(q,r)) * abs(p) / r + eps);
    }
    return 0;
}

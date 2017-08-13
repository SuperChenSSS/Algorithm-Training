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

int cal(){
    int a,b,c,d,e,f,abc;
    cin>>a>>b>>c>>d>>e>>f>>abc;
    int ab=d-abc,bc=e-abc,ca=f-abc;
    a-=ab+ca+abc,b-=ab+bc+abc,c-=bc+ca+abc;
    if(a<0||b<0||c<0||ab<0||bc<0||ca<0) return 0;
    return a+b+c+ab+bc+ca+abc;
}

int main(){
    int T;
    cin>>T;
    rep(i,0,T) {
        int n;
        cin>>n;
        int Max=-1;
        rep(i,0,n) Max=max(Max,cal());
        cout<<Max<<endl;
    }
    return 0;
}

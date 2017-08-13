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

const int N = 1e4 + 10;
int T,m,n;
char s[N];

int main(){
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%s",&m,s);
        int Mx=0;
        n=strlen(s);
        rep(i,0,n){
            for(int l=i,r=i,pl=l,pr=r,dif=0;0<=l&&r<n;++r,--l){
                dif+=abs((int)s[r]-s[l]);
                while(pr<=r&&dif>m) dif-=abs((int)s[pr++]-s[pl--]);
                Mx=max(Mx,r-pr+(pr!=i));
            }
        }
        rep(i,1,n){
            for(int l=i-1,r=i,pl=l,pr=r,dif=0;0<=l&&r<n;++r,--l){
                dif+=abs((int)s[r]-s[l]);
                while(pr<=r&&dif>m) dif-=abs((int)s[pr++]-s[pl--]);
                Mx=max(Mx,r-pr+1);
            }
        }
        printf("%d\n",Mx);
    }
    return 0;
}

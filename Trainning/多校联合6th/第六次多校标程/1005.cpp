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

bool out;
const int P = 1e9 + 7 , N = 8;
int n , m , sx , sy , iskey[N][N];
string board[N];
map<vi,int> f[2][1<<N];
int c , len , colnum[N];
const vi FINISH(0,0);
const vi ERROR(1,-1);
inline void Update(int &x,int d){
    x += d;if(x >= P) x -= P;
}
vi norm(vi v){
    if(v==FINISH) return FINISH;
    static int f[N];
    rep(i,0,len) f[i]=-1;
    int cnt=0;
    rep(i,0,len) v[i]=v[i]>=4?v[i]:(f[v[i]]==-1?f[v[i]]=cnt++:f[v[i]]);
    return v;
}
vi change(vi v,int A,int B){
    if(v==FINISH || A*B==20) return FINISH;
    if(B>=4) swap(A,B);
    rep(i,0,len) v[i]=v[i]==B?A:v[i];
    return norm(v);
}
vi isolate(vi v,int k){
    if(v==FINISH) return FINISH;
    int cnt=0;rep(i,0,len) cnt+=v[i]==v[k];
    if(v[k]>=4&&cnt==1) return ERROR;
    static int f[N];
    rep(i,0,len) f[i]=-1;
    cnt=0;
    rep(i,0,len) if(i!=k) v[i]=v[i]>=4?v[i]:(f[v[i]]==-1?f[v[i]]=cnt++:f[v[i]]);
    v[k]=cnt;
    return norm(v);
}
void Trans(int x,int y,vi v,int mask,int cnt){
    if(v==FINISH || !iskey[x][y]) Update(f[c][mask][v],cnt);
    else {
        int k=colnum[y];
        if(board[x][y]=='@') v=change(v,4,v[k]);
        Update(f[c][mask][v],cnt);
        if(v==FINISH) return;
        if((mask>>y&1)&&find(all(v),5)==v.end()) {
            v=change(v,5,v[k]);
            //for(auto e:v)cout<<e<<" ";cout<<endl;
            //cout<<(mask^1<<y)<<" "<<cnt<<endl;
            Update(f[c][mask^1<<y][v],cnt);
        }
    }
}

int main(){
    double t1 = clock();
    int T;cin >> T;
    rep(i,0,T) {
        cin >> n >> m;
        rep(i,0,n) cin >> board[i];
        rep(i,0,n) rep(j,0,m) if(board[i][j] == '@')
            sx = i, sy = j;
        len = 0;
        rep(i,0,m) colnum[i]=(i%2==sy%2)?len++:-1;
        rep(i,0,n) rep(j,0,m)
            iskey[i][j] = i % 2 == sx % 2 && j % 2 == sy % 2;
        rep(i,0,1<<m) f[c][i].clear();
        vi init_state(len , 0);
        rep(i,0,len) init_state[i]=i;
        f[c][0][init_state]=1;
        rep(i,0,n) rep(j,0,m){
            c ^= 1;rep(i,0,1<<m) f[c][i].clear();
            //cout << "start " << i << " " << j << endl;
            rep(mask,0,1<<m) for(auto e : f[c^1][mask]){
                vi v=e.fi;int nmask=mask;
                auto jump = [&](int x,int y){
                    return !iskey[x][y]&&y%2==sy%2;
                };
                // |
                if(mask>>j&1) {
                    if(board[i][j]!='X') nmask^=1<<j;
                    else continue;
                } else if(board[i][j]!='X') {
                    nmask^=1<<j;
                } else if(jump(i,j)){
                    v=isolate(v,colnum[j]);
                    if(v==ERROR) continue;
                }

                Trans(i , j , v , nmask , e.se);

                // .--
                if((i%2!=sx%2||j==m-1||iskey[i][j])&&j>=1&&(nmask>>(j-1)&3)==3){
                    vi nv=v;
                    if(iskey[i][j]&&colnum[j]>=1&&v!=FINISH) nv=change(v,v[colnum[j]-1],v[colnum[j]]);
                    if(jump(i,j)) nv=isolate(nv,colnum[j]);
                    else if(jump(i,j-1)) nv=isolate(nv,colnum[j-1]);
                    if(nv!=ERROR) Trans(i , j , nv , nmask^3<<(j-1) , e.se);
                }

                // --.
                if(iskey[i][j]&&j>=2&&(nmask>>(j-2)&3)==3){
                    vi nv=v;
                    if(iskey[i][j]&&colnum[j]>=1&&v!=FINISH) nv=change(v,v[colnum[j]-1],v[colnum[j]]);
                    if(jump(i,j-1)) nv=isolate(nv,colnum[j-1]);
                    else if(jump(i,j-2)) nv=isolate(nv,colnum[j-2]);
                    if(nv!=ERROR) Trans(i , j , nv , nmask^3<<(j-2) , e.se);
                }
            }
            //cout << "finish " << i << " " << j << endl << endl;
        }
        cout << f[c][0][FINISH] << endl;
    }
    //cerr << "std : " << (clock() - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}

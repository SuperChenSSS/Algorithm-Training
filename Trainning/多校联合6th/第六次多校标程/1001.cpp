// #include {{{
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

const int N = 5e5 + 10 , M = 26;
int T,n,Q;
char s[N],t[N];
static const int NODE = N * 18;
int h[N] , sum[NODE] , ls[NODE] , rs[NODE];


struct Trie{
    int go[N][M] , ed[N] , rt , sz;
    int newnode(){ed[sz]=0,memset(go[sz],0,sizeof(go[sz]));return sz++;}
    void ini(){sz=0;rt=newnode();}
    void ins(char *s,int id){
        int c=rt;
        for(int i=0;s[i];++i){
            int ch=s[i]-'a';
            if(!go[c][ch]) go[c][ch]=newnode();
            c=go[c][ch];
        }
        ed[c]=id;
    }
    int _,rk[N],lft[N],rgt[N];
    void dfs(int c){
        lft[c]=N,rgt[c]=0;
        if(ed[c]) lft[c]=rgt[c]=rk[ed[c]]=++_;
        rep(i,0,M) if(go[c][i]) {
            int t=go[c][i];
            dfs(t);
            lft[c]=min(lft[c],lft[t]);
            rgt[c]=max(rgt[c],rgt[t]);
        }
    }
    void getrank(){
        _=0;
        dfs(rt);
    }
    int run(const char *s){
        int c=rt;
        for(int i=0;s[i];++i){
            int ch=s[i]-'a';
            if(!go[c][ch]) return -1;
            c=go[c][ch];
        }
        return c;
    }
    pii queryrange(const char *s){
        int c=run(s);
        if(c==-1) return mp(-1,-1);
        return mp(lft[c],rgt[c]);
    }
    int newnode2(){
        ++_; ls[_]=rs[_]=sum[_]=0;
        return _;
    }
    void ins(int &c,int l,int r,int x){
        if(!c) c=newnode2();
        sum[c]++;
        if(l==r) return;
        int m=(l+r)>>1;
        if(x <= m) ins(ls[c],l,m,x);
        else ins(rs[c],m+1,r,x);
    }
    void insvalue(const char *s,int num){
        for(int c=rt,i=0;s[i];++i){
            int ch=s[i]-'a';
            c=go[c][ch];
            ins(h[c],1,n,num);
        }
    }
    void preparetree(){
        _=0;
        rep(i,0,sz) h[i]=0;
    }
    int query(int c,int l,int r,int L,int R){
        if(!c) return 0;
        if(L <= l && r <= R) return sum[c];
        int m=(l+r)>>1,s=0;
        if(L <= m) s+=query(ls[c],l,m,L,R);
        if(R > m) s+=query(rs[c],m+1,r,L,R);
        return s;
    }
    int querysum(const char *s,pii range){
        int c=run(s);
        if(c==-1||range.fi==-1) return 0;
        return query(h[c],1,n,range.fi,range.se);
    }
    void printrank(){
        rep(i,1,n+1) printf("%d%c",rk[i]," \n"[i==n]);
    }
}prefix,suffix;

string S[N],A[N],B[N];
int idA[N],idB[N],ans[N];

int main(){
    db t1 = clock();
    scanf("%d",&T);
    rep(test,0,T){
        scanf("%d%d",&n,&Q);
        prefix.ini();suffix.ini();
        rep(i,1,n+1) {
            scanf("%s",s);
            prefix.ins(s,i);
            reverse(s,s+strlen(s));
            suffix.ins(s,i);
            S[i]=s;
            idA[i-1]=i;
        }
        prefix.getrank();
        suffix.preparetree();
        rep(i,0,Q){
            scanf("%s%s",s,t);
            A[i]=s,B[i]=t;
            reverse(all(B[i]));
            idB[i]=i;
        }
        sort(idA,idA+n,[&](int x,int y){return sz(S[x]) > sz(S[y]);});
        sort(idB,idB+Q,[&](int x,int y){return sz(A[x]) + sz(B[x]) > sz(A[y]) + sz(B[y]);});
        for(int i=0,j=0;i<Q;++i){
            int c=idB[i];
            for(;j<n&&sz(S[idA[j]]) >= sz(A[c]) + sz(B[c]);++j)
                suffix.insvalue(S[idA[j]].c_str(),prefix.rk[idA[j]]);
            ans[c]=suffix.querysum(B[c].c_str(),prefix.queryrange(A[c].c_str()));
        }
        rep(i,0,Q) printf("%d\n",ans[i]);
    }
    //cerr << (clock() - t1) / CLOCKS_PER_SEC << endl;
    return 0;
}

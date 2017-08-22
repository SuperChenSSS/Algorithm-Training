#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<multiset.h>
#include<algorithm>
//#include <tr1/unordered_map>
#define lson l,m,ls[rt]
#define rson m+1,r,rs[rt]
using namespace std;

#define N 3000010
#define LL long long
#define l(x) (x<<1)
#define r(x) (x<<1|1)

using namespace std;

map<int,LL> f,val;
int n,m;

int dep_max(int x)
{
    int ans = 0;
    while(x<=n) ans++, x = l(x);
    return ans;
}

int dep_min(int x,int &tmp)
{
    int ans = 0;
    while(x<=n) ans++, tmp = x, x = r(x);
    return ans;
}

LL calc(int x)
{
    if(x>n) return 0;
    LL ans = 0;
    if(f.count(x)) return f[x];
    int tmp;
    int dx = dep_max(x), dn = dep_min(x,tmp);
    if(dx!=dn) tmp = n;
    while(tmp!=x) ans+=tmp, tmp=tmp/2;
    return ans+x;
}

LL com_ask(int x)
{
    LL ans = 0;
    ans = calc(l(x))+calc(r(x))+x;
    LL dis = calc(x);
    int tmp = x/2, rt = x%2;
    while(tmp>=1)
    {
        dis += val.count(tmp)? val[tmp]:tmp;
        if(rt) ans = max(ans, calc(l(tmp))+dis);
        else ans = max(ans, calc(r(tmp))+dis);
        rt = tmp%2;
        tmp/=2;
    }
    return ans;
}

void com_change(int x,LL v)
{
    int tmp = x;
    val[x] = v;
    while(tmp>=1)
    {
        f[tmp] = max(calc(l(tmp)), calc(r(tmp))) + (val.count(tmp)? val[tmp]:tmp);
    //  cout << "test tmp = "<<tmp<<' '<<f[tmp]<<endl;
        tmp = tmp/2;
    }
}

int main()
{
    //freopen("in10.txt","r",stdin);
    cin>>n>>m;
    char cmd[11];
    int x;
    LL v;
    for(int i=1;i<=m;i++)
    {
        scanf("%s%d",cmd,&x);
        printf("%s %d\n",cmd,x);
        if(cmd[0]=='q') printf("%lld\n",com_ask(x));
        else
        {
            scanf("%lld",&v);
            com_change(x,v);
        }
    }
}

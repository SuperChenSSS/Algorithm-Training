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
#include<algorithm>

#define N 3000010
#define LL long long
#define l(x) (x<<1)
#define r(x) (x<<1|1)

using namespace std;

map<LL,LL> f,val;
int n,m;

int dep_max(LL x)
{
    int ans = 0;
    while(x<=n) ans++, x = l(x);
    return ans;
}

int dep_min(LL x,LL &tmp)
{
    int ans = 0;
    while(x<=n) ans++, tmp = x, x = r(x);
    return ans;
}

LL calc(LL x)
{
    if(x>n) return 0;
    LL ans = 0,ans2 = 0;
    if(f.count(x)) return f[x];
    LL tmp;
    int dx = dep_max(x), dn = dep_min(x,tmp);
    while(tmp!=x) ans+=tmp, tmp=tmp/2;
    if(dx!=dn)
	{
		tmp = n;
		while(tmp!=x) ans2+=tmp, tmp=tmp/2;
		ans = max(ans, ans2);
	}
    return max(ans,ans2)+x;
}

LL com_ask(LL x)
{
    LL ans = 0;
    ans = calc(l(x))+ calc(r(x))+(val.count(x)? val[x]:x);
    LL dis = calc(x);
    LL tmp = x/2, rt = x%2;
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

void com_change(LL x,LL v)
{
    LL tmp = x;
    val[x] = v;
    while(tmp>=1)
    {
        f[tmp] = max(calc(l(tmp)), calc(r(tmp))) + (val.count(tmp)? val[tmp]:tmp);
        tmp = tmp/2;
    }
}

int main()
{
    while(cin>>n>>m){
        char cmd[11];
        LL x,v;
        f.clear();
		val.clear(); 
        for(int i=1;i<=m;i++)
        {
            scanf("%s%lld",cmd,&x);
            if(cmd[0]=='q') printf("%lld\n",com_ask(x));
            else
            {
                scanf("%lld",&v);
                com_change(x,v);
            }
        }
    }
    return 0;
}

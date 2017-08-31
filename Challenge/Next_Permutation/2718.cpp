#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 1e6;
const int mod = (1e9+7);
ll PowerMod(ll a,ll b,ll c)
{
    ll ans = 1;
    a %= c;
    while(b>0)
    {
        if(b % 2 == 1)
            ans = ans * a % c;
        b /= 2;
        a = a * a % c;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<PowerMod(a,b,c)<<endl;
    return 0;
}

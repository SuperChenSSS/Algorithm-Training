//TDteam01
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
char arr[maxn];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>arr)
    {
        ll res = 0,num = 0,powm = 1;
        for(int i=strlen(arr)-1;i>=0;i--)
        {
            if(num!=0)
                powm *= 2;
            cout<<res<<" "<<powm<<" "<<arr[i]<<" "<<powm * arr[i]<<"\n";
            res += powm * arr[i];
            cout<<res<<" "<<powm<<" "<<arr[i]<<"\n";
            num++;
            cout<<res<<"\n";
        }
    }
    return 0;
}

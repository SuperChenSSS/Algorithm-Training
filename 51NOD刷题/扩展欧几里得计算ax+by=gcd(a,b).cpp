#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
/*扩展欧几里德算法是用来在已知a, b求解一组x，y，
使它们满足贝祖等式： ax+by = gcd(a, b) =d（
解一定存在，根据数论中的相关定理）。
扩展欧几里德常用在求解模线性方程及方程组中。
然后为了防止x是负数，一直加n加到正数为止*/
//计算：ax+by=gcd(a,b)=d
ll m,n,k;
void extend_ou(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return;
	}
	extend_ou(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp - (a/b) * y;
}
int main()
{
	ios::sync_with_stdio(false);
	int i,j,k;
	ll x,y;
	cin>>m>>n;
	extend_ou(m, n, x, y);
	while(x<0)
	{
		x += n;
	}
	cout<<x<<y<<endl;
	return 0;
}
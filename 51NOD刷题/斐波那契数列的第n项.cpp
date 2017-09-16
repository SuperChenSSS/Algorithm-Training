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
const ll mod = 1000000009;

struct matrix//定义矩阵结构体
{
	ll m[2][2];
}ans, base;

matrix multi(matrix a, matrix b)//定义矩阵乘法
{
	matrix tmp;
	for(ll i = 0; i < 2; ++i)
	{
		for(ll j = 0; j < 2; ++j)
		{
			tmp.m[i][j] = 0;
			for(ll k = 0; k < 2; ++k)
				tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
		}
	}
	return tmp;
}
ll fast_mod(ll n)  // 求矩阵 base 的  n 次幂
{
	base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
	base.m[1][1] = 0;
	ans.m[0][0] = ans.m[1][1] = 1;  // ans 初始化为单位矩阵
	ans.m[0][1] = ans.m[1][0] = 0;
	while(n)
	{
		if(n & 1)  //实现 ans *= t; 其中要先把 ans赋值给 tmp，然后用 ans = tmp * t
			ans = multi(ans, base);

		base = multi(base, base);
		n >>= 1;
	}
	return ans.m[0][1];
}
int main()
{
	ios::sync_with_stdio(false);
	ll number;
	while(cin>>number)
	{
		cout<<fast_mod(number)<<endl;
	}
	return 0;
}
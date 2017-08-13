//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>  
#include <bitset>  
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
struct BigInt
{
	const static int mod = 10000;
	const static int DLEN = 4;
	int a[600],len;
	BigInt()
	{
		memset(a,0,sizeof(a));
		len = 1;
	}
	BigInt(int v)
	{
		memset(a,0,sizeof(a));
		len = 0;
		do{
			a[len++] = v % mod;
			v /= mod;
		}while(v);
	}
	BigInt(const char s[])
	{
		memset(a,0,sizeof(a));
		int L = strlen(s);
		len = L / DLEN;
		if(L%DLEN)	len++;
		int index = 0;
		for(int i=L-1;i>=0;i -= DLEN)
		{
			int t = 0;
			int k = i - DLEN + 1;
			if(k<0)	k = 0;
			for(int j=k;j<=i;j++)
				t = t*10 + s[j] - '0';
			a[index++] = t;
		}
	}
	BigInt operator +(const BigInt &b)const
	{
		BigInt res;
		res.len = max(len,b.len);
		for(int i=0;i<=res.len;i++)
			res.a[i] = 0;
		for(int i=0;i<res.len;i++)
		{
			res.a[i] += ((i<len)?a[i]:0)+((i<b.len)?b.a[i]:0);
			res.a[i+1] += res.a[i]/mod;
			res.a[i] %= mod;
		}
		if(res.a[res.len]>0)	res.len++;
		return res;
	}
	BigInt operator *(const BigInt &b)const
	{
		BigInt res;
		for(int i=0;i<len;i++)
		{
			int up = 0;
			for(int j=0;j<b.len;j++)
			{
				int temp = a[i]*b.a[j] + res.a[i+j] + up;
				res.a[i+j] = temp % mod;
				up = temp / mod;
			}
			if(up!=0)
				res.a[i+b.len] = up;
		}
		res.len = len + b.len;
		while(res.a[res.len-1]==0 &&res.len > 1)
			res.len--;
		return res;
	}
	void output()
	{
		cout<<a[len-1];
		for(int i=len-2;i>=0;i--)
			printf("%4d",a[i]);
		cout<<"\n";
	}
};
int main()
{
	BigInt a,b;
	while(~scanf("%lld%lld",&a,&b))
	{
		printf("%lld",a+b);
	}
	return 0;
}
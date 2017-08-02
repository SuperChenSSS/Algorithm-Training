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
const int maxn = 110;
int s[110];  
/*
int gcd(int a,int b)
{
	return b==0 ? a : gcd(b,a%b);
}
*/
int gcd(int a , int b)
{
	if(b==0) return a;
	a %= b;
	return gcd(b,a);
}  
int main()  
{  
	int t,n,m,x,y;  
	cin>>t;  
	while(t--)  
	{  
		cin>>n>>m;  
		memset(s,0,sizeof(s));  
		s[1] = s[2] = 100;  
		for(int i = 0 ; i < m ; i++)  
		{  
			cin>>x>>y;  
			s[x] = y;  
		}  
		if(s[2]==100)
			s[2] = s[1];
		else
			s[2] = s[2];  
		int a = s[1] + s[2];  
		int b = a, pre = 0;  
		for(int i = n ; i >= 3 ; i--)  
		{  
			if(!s[i]) s[i] = pre;  
			else pre = s[i];  
			b += s[i];  
		}  
		int res = __gcd(a,b);  
		printf("%d/%d\n",a/res,b/res);  
	}
	return 0;  
} 
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
//求莫比乌斯函数
int n;
int MOD(int a,int b)
{
	return a - a / b * b;
}
int miu(int n)
{
	int cnt,k = 0;
	for(int i=2;i*i<=n;i++)
	{
		if(MOD(n,i))
			continue;
		cnt = 0;
		k++;
		while(MOD(n,i)==0)
		{
			n /= i;
			cnt++;
		}
		if(cnt>=2)
			return 0;
	}
	if(n!=1)
		k++;
	return MOD(k,2)?-1:1;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		cout<<miu(n)<<endl;
	}
	return 0;
}
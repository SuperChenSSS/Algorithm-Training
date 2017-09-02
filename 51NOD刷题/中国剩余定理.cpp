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
int p[maxn],m[maxn];
//中国剩余定理：一个正整数K，给出K Mod 一些质数的结果，求符合条件的最小的K。
int main()
{
	ios::sync_with_stdio(false);
	ll sum,k,n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>p[i]>>m[i];
		sum = 1,k = m[0];
		for(int i=0;i<n-1;i++)
		{
			sum *= p[i];//每次要加的数
			while(k%p[i+1]!=m[i+1])//判断是否得到正确的解
				k += sum;
		}
		cout<<k<<endl;
	}
	return 0;
}
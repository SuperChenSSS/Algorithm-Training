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
int a[maxn],b[maxn],c[maxn];
int main()
{
	int x,y,z;
	int dp[maxn][maxn];
	while(cin>>x>>y>>z)
	{
		int sum = x + y + z;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<x+y+z;i++)
			cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<sum;i++)
			for(int j=1;j<sum;j++)
			{
				
			}
	}
	return 0;
}
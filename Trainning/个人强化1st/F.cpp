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
const int maxn = 510;
ll a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],result[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		ll sum = 0,num = 0;
		memset(result,0,sizeof(result));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>b[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>c[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				sum += a[i+num][j+num] * b[j+num][i+num];
				if()
			}
	}
	return 0;
}
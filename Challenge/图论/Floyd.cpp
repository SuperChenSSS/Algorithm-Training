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
const int maxn = 1e3;
const int mod = (1e9+7); 
//求任意两点间的最短路问题:Floyd算法
int d[maxn][maxn];//d[u][v]表示边e=(u,v)的权值(不存在时设为INF，不过d[i][i]=0)
int V;
void floyd()
{
	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	
	return 0;
}
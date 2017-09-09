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
bool g1[60][60],g2[60][60];
int monkey[60],banana[60],place[60];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(g1,false,sizeof(g1));
		memset(g2,false,sizeof(g2));
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>monkey[i]>>banana[i];
			g1[monkey[i]][banana[i]] = true;
		}
		for(int i=0;i<m;i++)
		{
			cin>>banana[i]>>place[i];
			g2[banana[i]][place[i]] = true;
		}
	}
	return 0;
}
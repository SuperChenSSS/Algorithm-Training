//TDteam01
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
int n,v[maxn];

void init()
{
	int a;
	char ch = getchar();
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v[a] = i;
	}
}

bool judge()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(v[i]>=v[j] || 2*j-i<0)
				continue;
			if(2*j-i>=n)
				break;
			if(v[2*j-i]<=v[j])
				continue;
			return true;
		}
	return false;
}
int main()
{
	while(scanf("%d",&n)==1 && n)
	{
		init();
		printf("%s\n",judge()?"no":"yes");
	}
	return 0;
}
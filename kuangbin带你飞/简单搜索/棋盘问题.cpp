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
int n,k;
char qipan[10][10];
int state[10];
int total,qizi;
void dfs(int pos)
{
	if(k==qizi)
	{
		total++;
		return;
	}
	if(pos>=n)
		return;
	for(int i=0;i<n;i++)
		if(state[i]==0 && qipan[pos][i]=='#')
		{
			state[i] = 1;
			qizi++;
			dfs(pos+1);
			state[i] = 0;
			qizi--;
		}
	dfs(pos+1);
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>k && (n!=-1 && k!=-1))
	{
		total = qizi = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>qipan[i][j];
		dfs(0);
		cout<<total<<"\n";
	}
	return 0;
}
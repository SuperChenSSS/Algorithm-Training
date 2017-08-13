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
int n,u,v,root;
vector<int> vec[maxn];
int dfs(int x,int par)
{
	set<int> st;
	for(int i=0;i<vec[x].size();i++)
	{
		int cur = vec[x][i];
		if(cur==par)	continue;
		int t = dfs(cur,x);
		if(t==-1)	return -1;
		st.insert(t+1);
	}
	if(st.size()==0)	return 0;
	if(st.size()==1)	return *st.begin();
	if(st.size()==2 && par==0)	return *st.rbegin()+*st.begin();
	root = x;
	return -1;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int ans = dfs(1,0);
	if(ans ==-1 && root)	ans = dfs(root,0);
	while(ans%2==0)
		ans /= 2;
	cout<<ans<<endl;
	return 0;
}
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
char s[20];
int a[20],ans[20],book[30],n;
void dfs(int cnt)
{
	if(cnt==n)
	{
		for(int i=0;i<n;i++)
			cout<<ans[i];
		cout<<endl;
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(book[i]==0)
			{
				book[i] = 1;
				ans[cnt] = a[i];
				dfs(cnt+1);
				book[i] = 0;
				while(i<n-1&&a[i+1]==a[i])
					i++;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	n = strlen(s);
	for(int i=0;i<n;i++)
	{
		a[i] = s[i] - '0';
	}
	sort(a,a+n);
	dfs(0);
	return 0;
}
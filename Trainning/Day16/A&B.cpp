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
int n,m,k,q;

void pt(int x)
{
	if(x==1)	cout<<"Alice"<<"\n";
	else	cout<<"Bob"<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>q>>k;
		while(q--)
		{
			cin>>n>>m;
			int cx = n/(k+1),cy = m/(k+1);
			int yx = n%(k+1),yy = m%(k+1);
			if(k==1)
			{
				if((yx==0 && m>=n) || (yy==0 && n>=m))
					pt(1);
				else	pt((0^(n+m) & 1));
			}
			else
			{
				if((yx==0 && m>=n) || (yy==0 && n>=m))
					pt(1);
				else	pt((0^(min(cx,cy) & 1)^((n+m) & 1)));
			}
		}
	}
	return 0;
}
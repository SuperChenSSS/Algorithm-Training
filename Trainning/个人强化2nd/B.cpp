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
const int maxn = 1e3;
const int mod = (1e9+7); 
using namespace std;
char a[maxn][600],b[maxn][600];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];  
		for(int i=0;i<m;i++)
			cin>>b[i];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(strcmp(a[i],a[j])==0)
					n--;
		for(int i=0;i<m;i++)
			for(int j=i+1;j<m;j++)
				if(strcmp(b[i],b[j])==0)
					m--;
		if(n>m)
			cout<<"YES"<<endl;
		else if(n==m)
		{
			int blag=0,cnt=0;
			for(int i=0;i<n;i++)
			{
				blag=0;
				for(int j=0;j<m;j++)
					if(strcmp(a[i],b[j])==0)
					{
						blag=1;
						break;
					}
					if(blag) 
						cnt++;
			}
			if(cnt%2)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
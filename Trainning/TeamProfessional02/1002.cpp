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
int arr[maxn][maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		char ch;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				while((ch = getchar()) == ' '|| ch=='\n'); 
				if(ch != '?')
				{
					ungetc(ch,stdin);
					scanf("%d",&arr[i][j]);
				}
				else
					arr[i][j] = -1;
				cout<<arr[i][j]<<"\n";
			}
		
	}		
	return 0;
}
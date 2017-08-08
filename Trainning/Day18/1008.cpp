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
int b[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=m;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
		{
			int j;
			for(j=1;j<=m;j++)
				if(b[j])	break;
			if(i==n)
			{
				//cout<<j<<"\n";
				printf("%d\n",j);
				break;
			}
			//cout<<j<<" ";
			printf("%d ",j);
			for(int t=j;t<=m;t++)
				b[t] = b[t] - b[t-j];
		}
	}
	return 0;
}

/*int b[maxn];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for (int i=0;i<=m;i++)
		{
			scanf("%d",&b[i]);
		}
		for (int i=1;i<=n;i++)
		{
			int j;
			for (j=1;j<=m;j++)
				if (b[j]) break;
			if (i==n) {printf("%d\n",j);break;}
			printf("%d ",j);
			for (int t=j;t<=m;t++)
			{
				b[t]=b[t]-b[t-j];
			}
		}
	}
	return 0;
}*/
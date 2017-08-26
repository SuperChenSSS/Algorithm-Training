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
ll arr[maxn][maxn];
ll heng[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		memset(arr,0,sizeof(arr));
		memset(heng,0,sizeof(heng));
		ll sum = 0;
		ll num = -1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(j==0)
					num++;
				heng[num] += arr[i][j];
			}
		//cout<<heng[0]<<heng[1]<<heng[2];
		for(int i=0;i<n;i++)
		{
			sum += heng[i];
		}
		sum /= (n-1);
		//cout<<sum<<"\n";
		num = 0;
		for(int i=0;i<n;i++)
		{
			arr[i][i] =  sum - heng[num++];
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(j==n-1)
					cout<<arr[i][j]<<"\n";
				else
					cout<<arr[i][j]<<" ";
			}
	}
	return 0;
}
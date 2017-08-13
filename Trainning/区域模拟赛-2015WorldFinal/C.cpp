//@Team: TDteam01
//@Author: CMY
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
const int MAXN = 1e2+15;
const int mod = (1e9+7); 
int arr[MAXN][MAXN];
const int INF=0x3f3f3f3f;
bool vis[MAXN];
int num[MAXN];
int lowc[MAXN];
int main()
{
	//ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k)
	{
		memset(arr,0,sizeof(arr));
		/*for(int i=0;i<n;i++){
			for(int j=i+1;j<n+1;j++)
			{
				cin>>arr[i][j];
				cout<<i<<" "<<j<<" "<<arr[i][j]<<" \n";
				arr[j][i] = arr[i][j];
			}
		}*/
		for(int i=1;i<=n;i++)
		{
			cin>>arr[0][i];
			arr[i][0] = arr[0][i];
			for(int j=i+1;j<=n;j++){
				cin>>arr[i][j];
				arr[j][i] = arr[i][j];
			}
		}
		int ans = Prim(arr,n,k);
		cout<<ans<<"\n";
	}
	return 0;
}
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
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
using namespace std;
const int N = 200000 + 10;
const int M = 100000 + 10;
pair<int, int> arr[M], arrb[N];
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		arrb[i].first = arrb[i].second = i;
	for(int i=1;i<=m;i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr+1, arr+m+1, cmp);
	/*for(int i=1;i<=m;i++)
		cout<<arr[i].first<<" "<<arr[i].second<<"\n";*/
	for(int i=1, y;i<=m;i++)
	{
		y = arr[i].second;
		arrb[y].first = arrb[y+1].first = min(arrb[y].first, arrb[y+1].first);
		arrb[y].second = arrb[y+1].second = max(arrb[y].second, arrb[y+1].second);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cout << arrb[i].first << "  " << arrb[i].second << endl ;
	}
	for(int i=1;i<=n;i++){
		cout<<arrb[i].second-arrb[i].first+1;
		if(i==n)
			cout<<"\n";
		else
			cout<<" ";
	}
}
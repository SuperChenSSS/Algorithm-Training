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
ll arr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int yes = 0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];	
		for(int i=0;i<n;i++)
			if(arr[i]%2==0)
				yes++;
		if(yes>=n/2)
			printf("2 0\n");
		else
			printf("2 1\n");
	}			
	return 0;
}
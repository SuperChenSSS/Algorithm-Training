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
char arr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int zero,one;
	while(cin>>arr)
	{
		zero = 0,one = 0;
		for(int i=0;i<sizeof(arr);i++)
			if(arr[i]=='0')
				zero++;
			else if(arr[i]=='1')
				one++;
		if(zero<one)
			cout<<zero<<"\n";
		else
			cout<<one<<"\n";
	}
	return 0;
}
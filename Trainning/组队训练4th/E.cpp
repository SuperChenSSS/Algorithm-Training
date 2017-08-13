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

int main()
{
	int t;
	double a,b,ans;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<=b)	cout<<"0.000000\n";
		else	printf("%.6lf\n",log(a/b) + 1.0);
	}
	return 0;
}
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
//求n!的10进制长度：斯特林公式
//n!=sqrt(2*pi*n)*(n/e)^n
//求n的长度:res = (int)(log10(2*pi*n)/2 + n*log10(n/e)) + 1;
int main()
{
	ios::sync_with_stdio(false);
	int n,res;
	double e = exp(1);
	while(cin>>n)
	{
		res = (int)(log10(2*PI*n)/2+n*log10(n/e)) + 1;
		cout<<res<<endl;
	}
	return 0;
}
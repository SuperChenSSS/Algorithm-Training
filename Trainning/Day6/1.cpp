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
const int maxn = 100;

int main()
{
	double a = 1;
	int ans = 0,temp;
	int m,test = 0;
	while(cin>>m)
	
	{
		test++;
		ans = int(m * log10(2));
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
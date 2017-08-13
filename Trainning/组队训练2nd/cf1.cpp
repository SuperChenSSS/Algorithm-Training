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

int main()
{
	int s,v1,v2,t1,t2,sum1 = 0,sum2 = 0;
	while(cin>>s>>v1>>v2>>t1>>t2)
	{
		sum1 = s * v1 + 2 * t1;
		sum2 = s * v2 + 2 * t2;
		if(sum1>sum2)
			cout<<"Second\n";
		else if(sum1<sum2)
			cout<<"First\n";
		else if(sum1 == sum2)
			cout<<"Friendship\n";
	}
	return 0;
}
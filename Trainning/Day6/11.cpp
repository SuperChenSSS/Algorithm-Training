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
	long long n,k,test = 0;
	while(cin>>n>>k)
	{
		int res = 0;
		test++;
		if(k<=n-1)
			res = k;
		else if(n==2)
			if(k%2)
				res = 1;
			else
				res = 2;
		else if(((k-n+1)/(n-1))%2==0)
			if((k-n+1)%(n-1)==1)
				res = n;
			else if((k-n+1)%(n-1)==0)
				res = n - 2;
			else
				res = (k-n+1)%(n-1)-1;
		else
			if((k-n+1)%(n-1)==1)
				res = n-1;
			else if((k-n+1)%(n-1)==0)
				res = n - 2;
			else
				res = (k-n+1)%(n-1)-1;
		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
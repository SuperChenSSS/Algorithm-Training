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
	//ios::sync_with_stdio(false);
	int n;  
	while (~scanf("%d",&n) && n)  
	{  
		int num,result = 0;  
		while (n--)  
		{  
			scanf("%d",&num);  
			result ^= num;  
		}  
		printf("%d\n",result);  
	}  
  
	return 0;  
}  
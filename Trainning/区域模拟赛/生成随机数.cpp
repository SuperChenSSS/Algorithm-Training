#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
#include <time.h>
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e2;
const int mod = (1e9+7);


int main()
{
	freopen("2.txt","w+",stdout);
	ios::sync_with_stdio(false);
	srand(time(NULL));
	printf("1 %d\n",maxn);
	for(int i = 0;i<=maxn;++i)
	{
		printf("%d ",rand()%(201));
	}
	printf("\n");
	return 0;
}
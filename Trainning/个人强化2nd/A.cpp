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
	int n, sum, num, flag, a[27];  
	char c;  
	while(cin>>n)  
	{  
		getchar();  
		sum = num = 0;  
		memset(a, 0, sizeof(a));  
		for(int i=0; i<n; ++i)  
		{  
			c = getchar();  
			a[c-'a']++;  
		}  
		do  
		{  
			flag = 0;  
			for(int i=0; i<27; ++i)  
			{  
				if(a[i])  
				{  
					if(flag)  
					{  
						--a[i];  
						++num; 
					}  
					else  
					{  
						flag = 1;  
						--a[i];  
						++num;  
						++sum; 
					}  
				}  
				else  
					flag = 0;  
			}  
		}while(num != n);  
		printf("%d\n",sum);  
	}  
	return 0;  
}  
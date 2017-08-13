//@Team: TDteam01
//@Author: CMY
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
	//ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int year,month,day,inc = 0 ,dec = 0,tmp = 0;
		scanf("%4d-%2d-%2d",&year,&month,&day);
		for(int i=year;inc<=7;i++)
		{
			if(year % 400 ==0 || year%4==0 && year%100!=0 && (month<2||(month==2&&day<29)))
				dec++;
			else
				inc++;
			tmp = year + inc - dec;
		}
		printf("%d\n",tmp);
		//cout<<tmp-2<<"\n";
	}
	return 0;
}
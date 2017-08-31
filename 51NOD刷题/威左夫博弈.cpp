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
//威左夫博弈：首先求出差值，差值 * 1.618 == 最小值 的话后手赢，否则先手赢。
//1.618=1+0.618,黄金比例=(1+sqrt(5))/2
int main()
{
	ios::sync_with_stdio(false);
	int t,a,b,huangjin;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		huangjin = (b-a)*(sqrt(5)+1)/2;
		if(huangjin==a)
			cout<<"B\n";
		else
			cout<<"A\n";
	}
	return 0;
}
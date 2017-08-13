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
	int t,c;
	int num = 0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>c;
		if(c<=35)
			num++;
	}
	cout<<num<<"\n";
	return 0;
}
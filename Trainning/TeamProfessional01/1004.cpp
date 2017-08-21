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
int n,x,sum;
string s;
	
int main(){
	while(cin>>n)
	{
	for(x=1;sum<n;x++)
		sum += x;
	x--;
	for(int i=0;i<x;i++)
		s += ')';
	for(int i=0;i<x;i++)
		s += '(';
	swap(s[x],s[x-(sum-n)]);
	cout<<s<<"\n";
	}
	return 0;
}
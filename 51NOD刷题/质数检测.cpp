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
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
int change(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,x;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(change(x)==0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}
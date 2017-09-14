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
const int maxn = 1e7;
const int mod = (1e9+7); 
int arr[maxn];
int main()
{
	ios::sync_with_stdio(false);
	freopen("GG.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<1e7;i++)
		cin>>arr[i];
	for(int i=0;i<1e7;i++)
		cout<<arr[i];
	return 0;
}
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
	int t;
	char arr1[maxn],arr2[maxn];int same,dif,temp1,temp2,t1,t2;
	cin>>t;
	while(t--)
	{
		same = 0;
		int n=0,x=0,y=0;
		cin>>n>>x>>y;
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<n;i++)
			cin>>arr2[i];
		for(int i=0;i<n;i++)
			if(arr1[i]==arr2[i])
			{
				++same;
			}
		dif = n - same;
		t1 = abs(x-y);
		temp1 = x>same?x-same:0;
		temp2 = y>same?y-same:0;
		if(t1>dif||(temp1)&&temp2&&temp1+temp2>dif)
			cout<<"Lying\n";
		else 
			cout<<"Not lying\n";
	}	
	return 0;
}
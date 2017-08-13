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
int arr[maxn];
int test[maxn];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int ngcd(int *a,int n)
{
	if(n==1)
		return *a;
	else
		return gcd(a[n-1],ngcd(a, n-1));
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int num =  0;
		int ans = 0;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		if(n==4){
			ans = ngcd(arr,4);
			if(ans==1)
				num++;
		}
		else
		{
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++){
					if(arr[j] % arr[i] !=0){
						num++;
						continue;
					}
					for(int k=j+1;k<n;k++){
						if(arr[k] % arr[i] !=0){
							num++;
							continue;
						}
						for(int l=k+1;l<n;l++)
						{
							if(arr[l] % arr[i] != 0)
							{
								num++;
								continue;
							}
						}
					}
				}
		}
		cout<<num<<"\n";
	}
	return 0;
}
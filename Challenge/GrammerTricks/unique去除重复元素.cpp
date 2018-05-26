#include <iostream> 
#include <cstdio>  
#include <cstring>  
#include <algorithm>   
#include <string>  
#include <vector>  
#include <cmath>  
#include <queue> 
using namespace std;  
typedef long long ll;     
const int INF = 1e9;  
const int maxn = 1e6;
const int mod = (1e9+7); 
int w,h,n;
int arr[] = {1,1,1,1,1,1,2,2,2,4,2,5,5,5,6};
vector<int> myarr (arr,arr+15);
vector<int>::iterator it;
int main()
{
	//freopen("1.txt","r",stdin);
	ios::sync_with_stdio(false);
	it = unique(myarr.begin(),myarr.end());
	myarr.resize(distance(myarr.begin(), it));
	for(it=myarr.begin();it!=myarr.end();it++)
		cout<<*it<<" ";
	return 0;
}
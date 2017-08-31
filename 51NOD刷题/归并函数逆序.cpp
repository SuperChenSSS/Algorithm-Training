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
ll a[maxn],b[maxn];
ll ans = 0;
//将有序的a[first...mid]和a[mid+1...last]归并为有序的b[first...last]
void Merge(ll *a,ll *b,int first,int mid,int last)
{
	int i = first,j = mid + 1;
	int cur = first;
	while(i<=mid && j<=last)
	{
		if(a[i]<=a[j])
			b[cur++] = a[i++];
		else 
		{
			b[cur++] = a[j++];
			ans += mid - i + 1;//关键步骤
		}
	}
	while(i<=mid)
	{
		b[cur++] = a[i++];
	}
	while(j<=last)
	{
		b[cur++] = a[j++];
	}
}

//将a[first...last]归并排序为b[first...last]
void Msort(ll *a,ll *b,int first,int last)
{
	int mid;
	if(first<last)
	{
		mid = (first+last)/2;
		Msort(b,a,first,mid);
		Msort(b,a,mid+1,last);
		Merge(a,b,first,mid,last);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	Msort(a,b,0,n-1);
	cout<<ans<<"\n";
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e6;
int arr[maxn+10];
int main()
{
	int n,k;
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n-k+1;i++)
	{
		if(i==n-k){
			cout<<*min_element(arr+i,arr+i+k)<<"\n";
		}
		else
			cout<<*min_element(arr+i, arr+i+k)<<" ";
	}
	for(int i=0;i<n-k+1;i++)
		{
			if(i==n-k)
				cout<<*max_element(arr+i,arr+i+k)<<"\n";
			else
				cout<<*max_element(arr+i, arr+i+k)<<" ";
		}
	return 0;
}
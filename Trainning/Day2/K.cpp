#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long arr[100005],tmp[100005];
int main()
{
	//freopen("k.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		tmp[i] = arr[i];
	}
	for(int l=0;l<m;l++)
	{
		int i1,j1,k1,num=0;
		cin>>i1>>j1>>k1;
		if(i1==j1){
			cout<<arr[i1-1]<<"\n";
			continue;
		}
		sort(arr+i1-1,arr+j1);
		for(int i=i1-1;i<=j1-1;i++)
		{
			num++;
			if(num == k1)
				cout<<arr[i]<<"\n";
		}
		for(int i=i1-1;i<=j1-1;i++)
			arr[i] = tmp[i];
	}
	return 0;
}
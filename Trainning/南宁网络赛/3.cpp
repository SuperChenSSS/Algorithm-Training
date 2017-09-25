#include <cstdio>
#include <iostream>
using namespace std;
int maxSumIS( long long arr[], long long n )
{
	long long  i, j, max = 0;
	long long msis[n],dp[n];
	for ( i = 0; i < n; i++ )
	{
		if(arr[i]<0)
			msis[i] =0;
		else if(arr[i]>=10000)
		{
			msis[i] =5;
			arr[i]%=10000;
		}
		else
		{
			msis[i] =1;
		}
	}
	for ( i = 0; i < n; i++ )
		dp[i]=msis[i];

	for ( i = 0; i < n; i++ )
		for ( j = i+1; j < n; j++ )
			//if ( arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
			if ( arr[j] >= arr[i] &&dp[j]<msis[j] + dp[i])
				dp[j] = msis[j] + dp[i];
	for ( i = 0; i < n; i++ )
	   cout<<dp[i]<<endl;
		if ( max < dp[i] )
			max = dp[i];
	return max;
}
long long size[210000];
int main()
{   
	ios::sync_with_stdio(false);
	//freopen("2.txt", "r", stdin);
	long long n=0,i=0;
	while(cin>>size[i++])
	{
		n++;
		if(size[i-1]<0)
		{
			n--;
			i--;
		}
		for(int i=j+1;j<n;j++)
		{
			if(arr[i]==arr[j])
				continue;
			else if(arr[i]<arr[j])
			{
				bool flag = false;
				
			}
		}
	}
	cout<<maxSumIS(size,n)<<endl;
	return 0;
}
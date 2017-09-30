#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std ;
const int maxn = 1e3 ;
int arr[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false) ;
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int n,k,tmp;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0];
		for(int j=1;j<=arr[i][0];j++)
			cin>>arr[i][j];
	}
	int sum = 0 ;
	int sumk = 0 ;
	int index = 1 ;
	while(sumk < k)
	{
		for(int i = 0 ; i < n ; i ++)
		{
			if(index > arr[i][0])
			{
				sum = sum + 50 ;
				sumk ++;
				if(sumk == k)
				{
					break ;
				}
				continue ;
			}
			if(sum <= arr[i][index])
			{
				sum = sum + arr[i][index] ;
				sumk ++ ;
				if(sumk == k)
				{
					break ;
				}
			}
		}
		index ++ ;
	}
	cout << sum << endl;
	return 0;
}
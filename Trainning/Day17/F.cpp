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

bool BinarySearch(int *a, int begin,int end, int num)
{
	if(begin>end)
	{
		return false;
	}
	int mid=(begin+end)/2;
	if(num==a[mid])
	{
		return true;
	}
	else
	{
		if(num<a[mid])
		{
			return BinarySearch(a,begin,mid-1,num);
		}
		else
		{
			return BinarySearch(a,mid+1,end,num);
		}
	}
	return false;
}

int main()
{
	int a[1001];
	int n,i,j,k,place;
	int num1,num2;
	bool isExist;
	while(cin>>n && n)
	{
		isExist=false;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=n-1;i>=0;i--)
		{
			if(isExist)
			{
				break;
			}
			for(j=0;j<n-1;j++)
			{
				if(isExist)
				{
					break;
				}
				if(i==j)
				{
					continue;
				}
				num1=a[i]-a[j];
				for(k=j+1;k<n;k++)
				{
					if(k==i)
					{
						continue;
					}
					num2=num1-a[k];
					if(num2==a[i]||num2==a[j]||num2==a[k])
					{
						continue;
					}

					if(BinarySearch(a,0,n-1,num2))
					{
						cout<<a[i]<<endl;
						isExist=true;
						break;
					}
				}
			}
		}
		if(!isExist)
		{
			cout<<"no solution"<<endl;
		}
	}
	return 0;
}
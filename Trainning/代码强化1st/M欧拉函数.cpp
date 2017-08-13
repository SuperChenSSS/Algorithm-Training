#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int result[1000005];
long long num;
int main()
{
	memset(result,0,sizeof(result));
	for(int i=2;i<=1000000;i++)
	{//筛选法
		if(!result[i])
		{
			for(int j=i;j<=1000000;j+=i)
			{
				if(!result[j])
					result[j] = j;
				result[j] = result[j] / i * (i-1);
			}
		}
	}
	while(cin>>n && n!=0)
	{
		num = 0;
		for(int i=2;i<=n;i++)
			{
				num += result[i];
			}
		cout<<num<<endl;
	}
	return 0;
}
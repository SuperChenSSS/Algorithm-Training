#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long eular(long long n)
{
	long long ans = n;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			ans -= ans/i;
			while(n%i==0)
				n /= i;
		}
	}
	if(n>1)
		ans -= ans/n;
	return ans;
}
int main()
{
	
	return 0;
}
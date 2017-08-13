#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
using namespace std;
int T,ans;
long long p,n;

int main()
{
	cin>>T;
	while(T--)
	{
		ans = 1;
		cin>>p;
		for(long long i = 2;i < p;++i)
		{
			if(p%i == 1)
			{
				n = i;
				break;
			}
		}
		for(int i = 1;(int)pow(n,i)<p;++i)
		{
			++ans;
		}
		cout<<ans<<"\n";
	}
}
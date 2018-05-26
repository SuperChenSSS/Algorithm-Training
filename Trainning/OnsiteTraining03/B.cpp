#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
const int maxn = 1005;
int arr[maxn],state[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,s;
	while(cin>>n)
	{
		memset(state,0,sizeof(state));
		int tmp,tmpb,res = 0;
		for(int i=0;i<n;i++)
		{

			cin>>tmp;
			while(tmp != 0)
			{
				s = tmp % 10;
				state[i] |= (1<<s);
				tmp/=10;
			}
		}
		sort(state,state+n);
		for(int i=0;i<n;i++)
		{
			if(state[i]!=state[i+1])
				res++;
		}
		cout<<res<<endl;
	}
	return 0;
}
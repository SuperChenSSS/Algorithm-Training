#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5;
const int MOD = (1e9+7);
int main()
{
	int n,ai[maxn],bi[maxn];
	while(cin>>n)
	{
		int next = 0,index = 0;
		for(int i=0;i<n;i++)
			cin>>ai[i];
		for(int i=0;i<n;i++)
			cin>>bi[i];
		sort(bi,bi+n);
		int left = 0,maxm = 0;
		for(int i=n+1;i<=2*n-1;i++)
		{
			next = bi[index++];
			for(int j=next; j<n+next; j++)
			{
				left = ai[j] - j - 1;
				if(maxm<left)
				{
					maxm = left;
					//cout << left << " " ;
				}
			}
			ai[n+next] = maxm;
			next++;
		}
		int sum = 0;
		for(int i=n;i<2*n;i++)
			sum += ai[i];
		cout<<sum<<"\n";
	}
	return 0;
}
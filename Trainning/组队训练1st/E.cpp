#include <iostream>
#include <cstdio>
 #include <algorithm>
typedef long long ll;
using namespace std;
const int MAX = 200001;
 
ll a[MAX],b[MAX],c[MAX];
 
int main()
{
	int n;
	while(scanf("%d",&n)==1&&n) 
	{
 
		for(int i=0;i<n;i++)
		{
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			a[i]=x-y;
			b[i]=y-z;
			c[i]=x-z;
		}
		sort(a,a+n);sort(b,b+n);sort(c,c+n);
		ll cnt=0;
		for(int i=0;i<n;i++)
		{
			cnt+=i*a[i]-(n-i-1)*a[i];
			cnt+=i*b[i]-(n-i-1)*b[i];
			cnt+=i*c[i]-(n-i-1)*c[i];
		}
		printf("%lld\n",cnt/2);
	}
	return 0;
}
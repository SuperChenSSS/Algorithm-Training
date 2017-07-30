//nupt2017team09
#include <stdio.h>
#include <algorithm>
#include <fstream>
using namespace std;
int a[250010],b[250010],c[250010];
int main()
{
	//ifstream fin("1.txt");
	int n,max1,i;

	while(scanf("%d",&n)!=EOF)
	{
	long long ans=0;
	//fin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//fin>>a[i];
		a[i]=a[i]-i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		//fin>>b[i];
	}
	sort(b+1,b+n+1);
	max1=0;
	for(i=b[1];i<=n;i++)
	{
		if(a[i]>max1)max1=a[i];
	}
	ans=ans+max1;
	max1=max1-n-1;
	/*for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	printf("\n");*/
	for(i=n;i>=1;i--)
	{
		if(a[i]>max1)max1=a[i];
		c[i]=max1;
	}

	/*printf("%d ",max1);
	for(i=1;i<=n;i++)
	printf("%d ",c[i]);
	printf("\n");*/
	for(i=2;i<=n;i++)
	{
		ans=ans+(long long)c[b[i]];
		ans=ans%(long long)(1e9+7);
	}
	printf("%lld\n",ans);
	}
	return 0;
}
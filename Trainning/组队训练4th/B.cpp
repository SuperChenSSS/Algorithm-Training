#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e4+2;
int T;
char colon;
int arr[maxn];

bool lol()
{
	for(int i = 0; i<T; ++i)
	{
		for(int j = 1; i + (j<<1) < T; ++j)
			if(arr[i]<arr[i+j]&&arr[i+j]<arr[i+(j<<1)])
				return false;
	}
	return true;
}

int main()
{
	int temp;
	//freopen("1.txt","r",stdin);
	while(cin>>T&&T!=0)
	{
		scanf("%c",&colon);
		for(int i = 0; i<T; ++i)
		{
			scanf("%d",&temp);
			arr[temp] = i;
		}
		if(lol())
			printf("yes\n");
		else
			printf("no\n");
	}
}
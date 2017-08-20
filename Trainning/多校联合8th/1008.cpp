//TDteam01
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
int a[1010];

int T,n,k,i;
int ub,lb;
int main()
{
	//freopen("1008.txt","r",stdin);
	ios::sync_with_stdio(false);
	char ch;
	scanf("%d",&T);
	while(T--)
	{
		ub = 0;
		lb = 0;
		n = 0;k = 0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		getchar();
		for(i=0;i<n;i++)
		{
			while((ch=getchar()) == ' ');
			switch(ch)
			{
				case 'L':ub+=a[i];break;
				case 'D':lb-=a[i];break;
				case 'N':ub+=a[i];lb-=a[i];break;
			}
		}
		if(k<=ub && k>=lb)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
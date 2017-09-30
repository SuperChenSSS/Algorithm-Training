#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <time.h>
#include <algorithm>
#include <set>
#define MM(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ULL;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const double pi=acos(-1);
using namespace std;
const int N=1e3+8;
 
char  a[N];
int flag[N];
 
void revse(int i)
{
		 a[i]=!(a[i]-'0')+'0';
}
 
int main()
{
		int n,x;
		while(~scanf("%d",&n))
		{
				MM(a,'\0');
				MM(flag,0);
				srand(time(0));
				while(1)
				{
						for(int i=1;i<=n;i++) a[i]=rand()%2+'0';
						printf("%s\n",a+1);
						fflush(stdout);
						scanf("%d",&x);
						if(x==n||x==n/2) break;
				}
				if(x==n/2)
				{
						revse(1);
						for(int j=2;j<=n;j++)
						{
								revse(j);
								printf("%s\n",a+1);
								fflush(stdout);
								scanf("%d",&x);
								if(x==n) break;
								else if(x==n/2) flag[j]=1;
								revse(j);
						}
						if(x!=n)
						{
								revse(1);
								for(int j=2;j<=n;j++) if(flag[j]) revse(j);
								printf("%s\n",a+1);
								fflush(stdout);
								scanf("%d",&x);
								if(x!=n)
								{
									for(int j=2;j<=n;j++) if(flag[j]) revse(j);
									revse(1);
									for(int j=2;j<=n;j++) if(!flag[j]) revse(j);
									printf("%s\n",a+1);
									fflush(stdout);
									scanf("%d",&x);
								}
						}
				}
		}
		return 0;
}
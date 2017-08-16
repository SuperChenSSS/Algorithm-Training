//Kolakosiki
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
const int maxn = 1e7+5;
int n,T;

int k[maxn];
void init()
{
	int next;
	int i = 2;
	int cnt = 2;
	k[0] = 1;
	k[1] = 2;
	k[2] = 2;
	while(cnt < maxn)
	{
		next = k[cnt] == 1?2:1;
		for(int m = 0;m < k[i];++m)
		{
			k[++cnt] = next;
		}
		++i;
	}
}

int main()
{
	init();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",k[n-1]);
	}
}

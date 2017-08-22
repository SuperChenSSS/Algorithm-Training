//TDteam01
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
const double eps=1e-6;
const int maxn = 125550;

int a[maxn];
int ans[maxn];
bool used[maxn];
map <int,int> num;
int n;
void solve(int a1,int a2)
{
	int sum = a1 + a2;
	num[sum]--;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		num.clear();
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			num[a[i]]++;
		}
		sort(a+1,a+n+1);
		solve(a[1],a[2]);
		int m = 2;
		ans[1] = a[1];
		ans[2] = a[2];
		int now = 3;
		while(now<=n)
		{
			if(num[a[now]]>0)
			{
				for(int i=1;i<=m;i++)
				{
					solve(ans[i],a[now]);
				}
				ans[++m] = a[now];
				num[a[now]]--;
			}
			now++;
		}
		cout<<m<<"\n";
		cout<<a[1];
		for(int i=2;i<=m;i++)
		{
			cout<<" "<<ans[i];
		}
		cout<<"\n";
	}
	return 0;
}
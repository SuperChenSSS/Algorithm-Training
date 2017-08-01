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
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
int n,t,k[maxn];
ll ans[maxn],cnt[maxn];
int a[maxn];
struct node{
	int l,r,i;
	bool operator <(const node a)const{
		return k[l]<k[a.l]||(k[l]==k[a.l]&&r<a.r);
	}
}q[maxn];

int main()
{
	cin>>n>>t;
	int m = ceil(sqrt(n));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=t;i++)
	{
		cin>>q[i].l>>q[i].r;
		k[q[i].l] = (q[i].l-1)/m+1;
		q[i].i = i;
	}
	sort(q+1,q+1+t);
	int l = 1,r = 0;
	ll tmp = 0,x;
	for(int i=1;i<=t;i++)
	{
		while(r<q[i].r)//add操作
		{
			x = a[++r];
			tmp += (2*cnt[x]+1)*x;
			++cnt[x];
		}
		while(l>q[i].l)//add操作
		{
			x = a[--l];
			tmp += (2*cnt[x]+1)*x;
			++cnt[x];
		}
		while(r>q[i].r)//remove操作
		{
			x = a[r--];
			tmp += (1-cnt[x]*2)*x;
			--cnt[x];
		}
		while(l<q[i].l)//remove操作
		{
			x = a[l++];
			tmp += (1-cnt[x]*2)*x;
			--cnt[x];
		}
		ans[q[i].i] = tmp;
	}
	for(int i=1;i<=t;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
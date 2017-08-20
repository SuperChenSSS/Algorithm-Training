//TDteam01
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
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
const int mod = (1e9+7); 
int a[maxn],n,d[maxn][20];
int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
//RMQ初始化
void init()
{
	for(int i=1;i<=n;i++)
		d[i][0] = a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			d[i][j] = gcd(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
//伪O(1)询问
int RMQ(int l,int r)
{
	int k=0;
	while((1<<(k+1))<=r-l+1)
		k++;
	return gcd(d[l][k],d[r-(1<<k)+1][k]);
}
//计数，爆int
map<int,ll> cnt;
/*
思路：枚举左端点，确定一个右端点（开始位置为当前左端点），然后二分寻找另一个最远的右端点，
使得该右端点到左端点区间内的最大公约数和原右端点到左端点的最大公约数相同，
用map计数，记录整个序列内公约数为某值的个数。最后询问时，区间公约数O（1）查询，相同公约数区间数O（logn）查询。
*/
int main()
{
	ios::sync_with_stdio(false);
	int t,le,rr,ri,ll,v,am,q,x,y;
	cin>>t;
	for(int ix=1;ix<=t;ix++)
	{
		cnt.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		init();
		for(int i=1;i<=n;i++)
		{
			//ll为当前左端点
			ll = i;
			//rr为当前右端点
			rr = i;
			while(rr<=n)
			{
				//le,ri为二分左右端点
				le = rr;
				ri = n;
				v = RMQ(ll, rr);
				while(le<=ri)
				{
					int mid = (le+ri) >> 1;
					if(RMQ(ll,mid)>=v)
						le = mid + 1;
					else
						ri = mid - 1;
				}
				//加上区间长度
				cnt[v] += le - rr;
				//下一次从当前枚举的最右右端点后一个位置开始
				rr = le;
			}
		}
		cin>>q;
		printf("Case #%d:\n",ix);
		for(int j=0;j<q;j++)
		{
			cin>>x>>y;
			v = RMQ(x, y);
			printf("%d %lld\n",v,cnt[v]);
		}
	}
	return 0;
}
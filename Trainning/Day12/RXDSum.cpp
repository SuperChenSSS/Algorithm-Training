#include <cstdio>  
#include <iostream>  
#include <sstream>  
#include <cstdlib>  
#include <cstring>  
#include <string>  
#include <climits>  
#include <cmath>  
#include <algorithm>  
#include <queue>  
#include <vector>  
#include <stack>  
#include <set>  
#include <map>  
#define INF 0x3f3f3f3f  
#define eps 1e-8  
using namespace std;  
  
const int MAXN = 100005;  
const int MAXM = 2000005;  
  
vector<int> has;  
int a[MAXN];  
int tot; 
int sum; 
  
struct NODE  
{  
	int count;  
	int left, right;  
};  
  
int root[MAXN];  
NODE node[MAXM];  
  
int null;  
  
int newnode(int count, int left, int right)  
{  
	node[tot].count=count;  
	node[tot].left=left;  
	node[tot].right=right;  
	return tot++;  
}  
  
int insert(int rt, int l, int r, int k)  
{  
	if (l <= k && k <= r)  
	{  
		if (l == r)  
		{  
			return newnode(node[rt].count + 1, 0, 0);  
		}  
		int m = (l + r) >> 1;  
		return newnode(node[rt].count + 1,  
					   insert(node[rt].left, l, m, k),  
					   insert(node[rt].right, m + 1, r, k));  
	}  
	return rt;  
}  
  
int query(int p, int q, int l, int r, int k)  
{  
	if (l == r)  
	{  
		return has[l];  
	}  
	int m = (l + r) >> 1;  
	int cot = node[node[q].left].count - node[node[p].left].count;  
	if (cot >= k)  
	{  
		return query(node[p].left, node[q].left, l, m, k);  
	}  
	return query(node[p].right, node[q].right, m + 1, r, k - cot);  
}  
  
int main()  
{  
	int cas;  
	scanf("%d", &cas);  
	while(cas --)  
	{  
		sum = 0;
		int n,k;  
		scanf("%d%d", &n, &k);  
		has.clear();  
		tot = 0;  
		for(int i = 1; i <= n; i ++)  
		{  
			scanf("%d", &a[i]);  
			has.push_back(a[i]);  
		}  
		sort(has.begin(), has.end());  
		has.erase(unique(has.begin(), has.end()), has.end());  
		int m = has.size();  
		null = newnode(0, 0, 0);  
		root[0] = newnode(0, 0, 0);  
		for(int i = 1; i <= n; i ++)  
		{  
			a[i] = lower_bound(has.begin(), has.end(), a[i]) - has.begin();  
			root[i] = insert(root[i - 1], 0, m - 1, a[i]);  
		}    
			int l,r;  
			//scanf("%d%d%d", &l, &r, &k);  
			for(int l=1;l<=n;l++)
				for(int r=l;r<=n;r++)
				{
					if(k<=r-l+1)
					{
						cout<<l<<r<<" ";
						cout<<query(root[l - 1], root[r-1], l, r, k)<<" ";
						sum += query(root[l - 1], root[r-1], l, r, k);   
					}
				} 
			cout<<sum<<"\n";
	}  
	return 0;  
}  
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>

#define Fori(x) for(int i=0;i<x;i++)
#define Forj(x) for(int j=0;j<x;j++)
#define maxn 100007
#define inf 0x3f3f3f3f
#define ONES(x) __builtin_popcount(x)
#define _  << "  " <<
using namespace std;

typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
inline int read(){ int cnt;    scanf("%d",&cnt);   return cnt;}

struct Node{
	int l,r;
}node[maxn];

bool cmp(Node a, Node b){
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
int l[maxn],r[maxn];
int main()
{
	int n,m;
	while(cin>>n>>m){
		for(int i = 0; i<n; i++){
			node[i].l = read(); node[i].r = read();
		}
		sort(node,node+n,cmp);
		int cnt = 0;
		l[cnt] = node[0].l;
		r[cnt] = node[0].r;
		for(int i = 1; i<n; i++){
			if(node[i].l<=r[cnt]+1)
				r[cnt] = max(r[cnt],node[i].r);
			else{
				l[++cnt] = node[i].l;
				r[cnt] = node[i].r;
			}
		}
		int ans = 0;
		int len = 0;
		int x = l[0];
		int y = r[0];
		for(int i = 1, j= 0; i<=cnt;){
			while(len+l[i]-r[i-1]-1 <= m && i<=cnt){
				len += (l[i]-r[i-1]-1);
				y = r[i];
				i++;
			}
			ans = max(ans,y-x+1+m-len);
			while(len+(l[i]-r[i-1]-1)>m && j<i){
				j++;
				len -= (l[j] - r[j-1] -1);
				x = l[j];
			}
		}
		ans = max(ans,y-x+1+m-len);
		cout<<ans<<"\n";
	}
	return 0;
}

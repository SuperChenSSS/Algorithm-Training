#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <stack>    
#include <cstdlib>  
#include <cmath> 
#include <map>  
#include <queue> 
using namespace std;  
typedef long long ll;  
const double PI = acos(-1.0);  
const double eps = 1e-6;  
const int INF = 1000000000;  
const int maxn = 1e6;
const int mod = (1e9+7); 
struct Point{
	ll a, b, c, d, e;
}nod[maxn];
bool vis[maxn];
ll check(Point aa, Point bb, Point cc) {
	return (bb.a-aa.a)*(cc.a-aa.a)+(bb.b-aa.b)*(cc.b-aa.b)+(bb.c-aa.c)*(cc.c-aa.c)+(bb.d-aa.d)*(cc.d-aa.d)+(bb.e-aa.e)*(cc.e-aa.e);
}
int main(){
	int n;
	memset(vis, true, sizeof(vis));
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> nod[i].a >> nod[i].b >> nod[i].c >> nod[i].d >> nod[i].e;
	int k = n;
	for(int i=1; i <= n; i ++) 
	{
		for(int j = 1; j <= n; j ++)
		{
			for(int l = j+1; l <= n; l ++) 
				if(i != j && i != l) 
					if(check(nod[i], nod[j], nod[l]) > 0) 
					{
						vis[i] = false;
						k--;
						goto tt;
					}
		}
		tt:;
	}
	printf("%d\n",k);
	int cnt = 0;
	for(ll i = 1; i <= n; i ++) {
		if(vis[i]) {
			cnt ++;
			cout<<i<<" ";
		}
	}
	if(k!=0)printf("\n");
	return 0;
}
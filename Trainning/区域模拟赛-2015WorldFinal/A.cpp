//@Team: TDteam01
//@Author: CMY
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>
#include <iomanip>  
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
struct node
{
	double val;
	int pos;
	node()
	{
		val = pos = 0;
	}
}ans[maxn];
bool cmp(node a,node b)
{
	return a.val > b.val;
}
int main()
{
	ios::sync_with_stdio(false);
	int p,a,b,c,d,n;
	while(cin>>p>>a>>b>>c>>d>>n)
	{
		double maxm = 0;
		for(int i=1;i<=n;i++){
			ans[i].val = p * (sin(a*i+b)+cos(c*i+d)+2);
			//cout<<ans[i].val<<" ";
			ans[i].pos = i;
		}
		sort(ans+1,ans+1+n,cmp);
		/*for(int i=1;i<=n;i++){
			cout<<ans[i].val<<" ";
		}*/
		for(int i=1;i<=n/2;i++)
			for(int j=n;j>=n/2;j--)
			if(  ans[j].pos > ans[i].pos && ans[i].val - ans[j].val > maxm)
				maxm = ans[i].val - ans[j].val;
		int  a = 10;
		//printf("%d",a);
		cout<<setprecision(10)<<maxm<<"\n";
	}
	return 0;
}
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
double ans[maxn],temp;
int main()
{
	ios::sync_with_stdio(false);
	int p,a,b,c,d,n,mark;
	while(cin>>p>>a>>b>>c>>d>>n)
	{
		double maxm = 0;
		temp = 0.00;
		for(int i=1;i<=n;i++){
			ans[i] = p * (sin(a*i+b)+cos(c*i+d)+2);
			//cout<<ans[i].val<<" ";
		}
		mark = 1;
		for(int i = 2;i<=n;++i)
		{
			if(ans[mark]>ans[i])
			{
				if(temp<ans[mark]-ans[i])
					temp = ans[mark]-ans[i];
			}
			if(ans[mark]<ans[i])
			{
				if(temp>maxm)
				    maxm = temp;
				//printf("%lf ",maxm);
				//cout<<maxm<<" ";
				mark = i;
				continue;
			}
		}
		if(maxm < temp)
		    maxm = temp;
		
		printf("%.6f",maxm);
		//cout<<setprecision(10)<<maxm<<"\n";
	}
	return 0;
}
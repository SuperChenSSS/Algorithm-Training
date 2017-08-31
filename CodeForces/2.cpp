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
typedef struct
{
	double x,y,r;
}yuan;
yuan point[maxn];
double distance(yuan p1,yuan p2) 
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)); 
}
int main()
{
	//freopen("2.txt","r",stdin);
	ios::sync_with_stdio(false);
	double r,d,n;
	yuan dian;
	double len;
	dian.x = dian.y = dian.r = 0;
	while(cin>>r>>d)
	{
		int num = 0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>point[i].x>>point[i].y>>point[i].r;
			len = distance(point[i], dian);
			if(len>=r-d+point[i].r && len<=r-point[i].r)
				num++;
		}
		cout<<num<<endl;
	}
	return 0;
}
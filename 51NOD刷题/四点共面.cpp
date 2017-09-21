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
struct point
{
	int x,y,z;
}p[4];
int is_SameMian(point a,point b,point c,point d)
{
	point ab,ac,ad;
	ab.x = a.x - b.x,ab.y = a.y - b.y,ab.z = a.z - b.z;
	ac.x = a.x - c.x,ac.y = a.y - c.y,ac.z = a.z - c.z;
	ad.x = a.x - d.x,ad.y = a.y - d.y,ad.z = a.z - d.z;
	int gg = ab.x * ac.y * ad.z + ab.y * ac.z * ad.x + ac.x * ad.y * ab.z;
	gg -= ab.z * ac.y * ad.x + ab.x * ac.z * ad.y + ab.y * ac.x * ad.z;
	return gg;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4;i++)
			cin>>p[i].x>>p[i].y>>p[i].z;
		int flag = is_SameMian(p[0], p[1], p[2], p[3]);
		if(!flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
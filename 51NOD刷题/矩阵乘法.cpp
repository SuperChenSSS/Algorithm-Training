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
const int maxn = 1e2;
const int mod = (1e9+7); 
struct Mat
{
	int p[maxn][maxn];
};
int n;
Mat mul(Mat a,Mat b)
{
	Mat c;
	memset(c.p,0,sizeof(c.p));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				c.p[i][j] += a.p[i][k] * b.p[k][j];
	return c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	Mat A,B;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A.p[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>B.p[i][j];
	Mat C = mul(A,B);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			printf("%d%c",C.p[i][j],j==n-1?'\n':' ');
	return 0;
}
//TDteam01
#include <cstdio>  
#include <cstring>  
#include <iostream> 
#include <algorithm> 
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
const int maxn = 1e3;
const int mod = (1e9+7); 
char a[maxn],b[maxn],arr[maxn];
char mat[maxn][maxn] = {0};
char maxf(char a,char b,char c)
{
	if(a>b)
		b = a;
	return b > c ? b : c;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(arr,0,sizeof(arr));
	scanf("%s%s",a+1,b+1);
	int i,j=0,k;
	for(i=1;a[i];i++)
		for(j=1;b[j];j++)
		{
			mat[i][j] = maxf(mat[i-1][j],mat[i][j-1],mat[i-1][j-1]+(a[i]==b[j]?1:0));
		}
	i--;j--;
	k = maxn - 1;
	while(i>0 && j>0)
	{
		if(a[i]==b[j])
		{
			arr[k--] = a[i];
			i--;j--;
		}
		else if(mat[i-1][j] > mat[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	printf("%s\n",arr+k+1);
	return 0;
}
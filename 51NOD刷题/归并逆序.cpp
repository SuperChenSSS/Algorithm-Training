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
int ans = 0;
int a[maxn],b[maxn];
void MergeSort(int *a,int *b,int x,int y)
{
	if(y-x>1)//递归至单个元素为一组
	{
		int mid = (y+x)/2;
		int p = x,q = mid,i = x;
		MergeSort(a, b, x, mid);//左递归
		MergeSort(a, b, mid, y);//右递归
		while(p<mid || q<y)//合并
		{
			if(q>=y||(p<mid && a[p]<=a[q]))
				b[i++] = a[p++];//将左边元素复制到临时数组
			else
			{
				b[i++] = a[q++];//将右边元素复制到临时数组
				ans += mid - p;//累计逆序对的数目
			}
		}
		for(int i=x;i<y;i++)//将临时数组里已排序的元素还原到原数组
			a[i] = b[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	MergeSort(a, b, 0, n);
	cout<<ans<<"\n";
	return 0;
}